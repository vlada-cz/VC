#-----------------------------------------------------------------------#
#   File: get_plots_memory_time.py
#
#   Description:    It is script for plot (show) memory and time consumption
#   
#   Usage:  python3.6 get_plots_memory_time.py  pathToFolderWithCSVs (extracted from test_base)
#   
#   Return:     The command above will create time.pdf and memory.pdf
#               and also show plot of time and memory
#
#   Dependecy:  matplotlib ! (on merlin there is no matplotlib -> pip install matplotlib -U)
#
#-----------------------------------------------------------------------#
#   Authors:    Vladimir Jerabek    <xjerab21@vutbr.cz>
#               Jan Kohut           <xkohut08@vutbr.cz>
#   
#   Date:       2018/11/28
#-----------------------------------------------------------------------#

import sys
import os
import csv
import numpy as np
import matplotlib.pyplot as plt
from glob import iglob
import glob


#-----------------------------------------------------------------------#
#Global params -> you cen CHANGE IT
#-----------------------------------------------------------------------#

#Path to csv file 
if len(sys.argv) > 1:
    csvDir = sys.argv[1]
else:
    print("Usage: " + sys.argv[0] + "pathToFolderWithCSVs" , file=sys.stderr)
    sys.exit(1)


#-----------------------------------------------------------------------#
#Function for load CSV file and return back numpy array
#
#args:
#   csvPath:    Path to csv file, which will be loaded
#-----------------------------------------------------------------------#
def loadCSV(csvPath):
    resultList =   [[[],[],[],[]],
                    [[],[],[],[]],
                    [[],[],[],[]],
                    [[],[],[],[]]]

    with open(csvPath, 'r') as csvFile:
        resultFile = csv.reader(csvFile, delimiter=',',
                                quotechar='|')
        for graph in resultFile:
            
            for i, algo in enumerate(graph):
                splitAlgo = algo.split(",")
                
                for j, batch in enumerate(splitAlgo):
                    splitBatch = batch.split(" ")

                    run = []

                    for value in splitBatch:
                        run.append(float(value))
                    
                    resultList[i][j].append(run)


    resultArray = np.array(resultList)
    
    #return array
    return resultArray


#-----------------------------------------------------------------------#
#Function for process CSV file into needed shape
#
#args:
#   csvPath:    Path to csv file, which will be processed
#-----------------------------------------------------------------------#
def processCSV(csvPath):
    #load csv
    csvLoaded = loadCSV(csvPath)
    avgArray = np.average(csvLoaded, axis=2)
    return avgArray


#save original path and after that change directory
originPath = os.getcwd()
os.chdir(csvDir)

vertexList = []
timeList = [[],[],[]]       #GIC, MDG, ME
memoryList = [[],[],[]]     #GIC, MDG, ME

#loop through CSVs in folder
for file in iglob("*.csv"):
    #get number of verticies
    numVertex = int(file.split('_')[-1].split('.')[0])
    vertexList.append(numVertex)

    #Process CSV file to get avrage of memory and time consumption
    #reuslt is like csvResult.shape(3,2) -> 3 algo, 2 time & memory
    avgArray = processCSV(file)
    
    for i in range(3):      #number of algo-s
        timeList[i].append(avgArray[i][0][0])
        memoryList[i].append(avgArray[i][0][2])


os.chdir(originPath)

vertexList.sort()
for i in range(3):
    timeList[i].sort()
    memoryList[i].sort()


# name of algoritms
name=['GIC', 'MDG','ME']


for i,timeAlgo in enumerate(timeList):
    plt.plot(vertexList, timeAlgo,label=name[i])

plt.xlabel('Počet vrcholů')
plt.ylabel('Spotřeba času [v ms]')
plt.grid(True)
plt.legend(loc='upper left')
plt.savefig("time.pdf")
plt.show()



for i,memoryAlgo in enumerate(memoryList):
    plt.plot(vertexList, memoryAlgo,label=name[i])

plt.xlabel('Počet vrcholů')
plt.ylabel('Spotřeba paměti [v B]')
plt.grid(True)
plt.legend(loc='upper left')
plt.savefig("memory.pdf")
plt.show()
