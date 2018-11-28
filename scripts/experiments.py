# Scripts for experiments

import sys
import os
import csv
import subprocess
import re
from tqdm import tqdm

#-----------------------------------------------------------------------#
#Global params -> you cen CHANGE IT
#-----------------------------------------------------------------------#

#Number of graphs which will be used for comparing (from each vertex folder)
graphsNum = 10


#relative path to vc -> program for comparing vertex cover algorithms
vcPath = "../build/vc"

#get absolute path to vc
originPath = os.getcwd()
VC = os.path.join(originPath, vcPath)

#set of algorithm, that can be tested
algorithms = ['GIC', 'MDG', 'ME', 'DUMMY']
 
# print(sys.argv)
# print(len(sys.argv))
# sys.exit(1)1

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
    for i in tqdm(range(graphsNum)):

        #random graph number
        #TODO
        resultList = []

        #loop through algorithms
        for j,algo in enumerate(algorithms):

            #Normal algo
            output = subprocess.check_output(
                ["valgrind", VC, "-g", "graph_" + str(i) + ".txt", "-m", algo, "-i", "1" ],
                stderr=subprocess.STDOUT)

            result0 = processOutput(output)

            #Algo with -p
            output = subprocess.check_output(
                ["valgrind", VC, "-g", "graph_" + str(i) + ".txt", "-m", algo, "-i", "1", "-p"],
                stderr=subprocess.STDOUT)

            result1 = processOutput(output)

            #Algo with -r
            output = subprocess.check_output(
                ["valgrind", VC, "-g", "graph_" + str(i) + ".txt", "-m", algo, "-i", "1", "-r"],
                stderr=subprocess.STDOUT)

            result2 = processOutput(output)

            #Algo with -p -r 
            output = subprocess.check_output(
                ["valgrind", VC, "-g", "graph_" + str(i) + ".txt", "-m", algo, "-i", "1", "-p", "-r"],
                stderr=subprocess.STDOUT)

            result3 = processOutput(output)

            resultList.append(result0 + "," + result1 + "," + result2 + "," + result3)
        
        resultFile.writerow(resultList)
