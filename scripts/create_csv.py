#-----------------------------------------------------------------------#
#   File: create_csv.py
#
#   Description:    It is script for creating CSV file in test_base.
#   
#   Usage:  python3.6 create_csv.py  pathToVertexFolder (in test_base/density_X_X)
#
#   Exampl: python3.6 create_csv.py test_base/density_10_1/vertex_size_10
#
#   
#   Return:     The command above will create csv file in test_base/density_X_X
#               from 150 graphs in specific density an also specific vertex folder.
#
#-----------------------------------------------------------------------#
#   Authors:    Vladimir Jerabek    <xjerab21@vutbr.cz>
#               Jan Kohut           <xkohut08@vutbr.cz>
#   
#   Date:       2018/11/22
#-----------------------------------------------------------------------#

import sys
import os
import csv
import subprocess
import re

#-----------------------------------------------------------------------#
#Global params -> you cen CHANGE IT
#-----------------------------------------------------------------------#

#Number of graphs which will be used for comparing (from each vertex folder)
graphsNum = 150


#relative path to vc -> program for comparing vertex cover algorithms
vcPath = "../build/vc"

#get absolute path to vc
originPath = os.getcwd()
VC = os.path.join(originPath, vcPath)

#set of algorithm, that can be tested
algorithms = ['GIC', 'MDG', 'ME', 'DUMMY']
 

if len(sys.argv) > 1:
    vertexPath = sys.argv[1]
else:
    print("Usage: " + sys.argv[0] + " pathToVertexFolder (from Test_base)" , file=sys.stderr)
    sys.exit(1)
   

#-----------------------------------------------------------------------#
# Function for mine results from output from subprocess.check_output()
#
# args:
#   output:     Output from subprocess.check_output()
#-----------------------------------------------------------------------#

def processOutput(output):
    #decode string from byte to ascii
    output = output.decode("ascii")
    #get only usfull info
    output = output.split("#")[-1]
    output = output.splitlines()[1:]

    #get number of allocated bytes
    for line in output:
        if re.search("total heap usage:", line):
            allocBytes = line.split(" ")[-3]
            allocBytes = allocBytes.replace(",","")

    results = output[0] + " " + allocBytes

    #return result
    return results



#-----------------------------------------------------------------------#
# Function for run subprocess with catching exceptions
#
# args:
#   argsList:   List of arguments for subprocess [i, algo, ["-p", "-r"]]
#   i.e.: argList = [30, "GIC", ["-p"]]
#-----------------------------------------------------------------------#
def runSubprocess(argsList) :
    
    args = ["valgrind", VC, "-g", "graph_" + str(argsList[0]) + ".txt", "-m", argsList[1], "-i", "1" ] + argsList[2]

    #if there was a good run on subprocess
    goodRun = False
    error = False

    #loop until good run is set to true
    while not goodRun: 

        try:
            #try to run subprocess
            output = subprocess.check_output(args, stderr=subprocess.STDOUT)

        except subprocess.CalledProcessError as e:
            print("WARNING:" + e.output, file=sys.stderr)
            error = True

        #if error occuers run it again
        if error:
            goodRun = False
            error = False
        else:
            goodRun = True
            result = processOutput(output)

    #return result
    return result


#-----------------------------------------------------------------------#
#Main function
#-----------------------------------------------------------------------#

#strip the last slash
if vertexPath.endswith('/'):
    vertexPath = vertexPath[:-1]

#name of result csv file
csvName = vertexPath + '.csv'

#create csv file for results
with open(csvName, 'w+') as csvfile:
    resultFile = csv.writer(csvfile, delimiter=',',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)

    #go to vertex directory
    os.chdir(vertexPath)

    #loop for number of graphs, which has to be used for test
    for i in range(graphsNum):

        #random graph number
        #TODO
        resultList = []

        #loop through algorithms
        for j,algo in enumerate(algorithms):

            #Normal algo
            result0 = runSubprocess([i, algo, []])

            #Algo with -p
            result1 = runSubprocess([i, algo, ["-p"]])

            #Algo with -r
            result2 = runSubprocess([i, algo, ["-r"]])

            #Algo with -p -r 
            result3 = runSubprocess([i, algo, ["-p","-r"]])

            #create list of results from one graph
            resultList.append(result0 + "," + result1 + "," + result2 + "," + result3)
        
        #write result into csv file
        resultFile.writerow(resultList)
    

    #return to original path
    os.chdir(originPath)
