#Script for show size of vertex cover using different algorithms

import sys
import os
import csv
import numpy as np
import matplotlib.pyplot as plt


#-----------------------------------------------------------------------#
#Global params -> you cen CHANGE IT
#-----------------------------------------------------------------------#

#Path to csv file 
if len(sys.argv) > 1:
    csvPath = sys.argv[1]
else:
    print("Usage: " + sys.argv[0] + " pathToCsvFile (in testbase)" , file=sys.stderr)
    sys.exit(1)


resultList =   [[[],[],[],[]],
                [[],[],[],[]],
                [[],[],[],[]],
                [[],[],[],[]]]

#load csv
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



density = input("Enter denisty of graphs: ")

#Count number of wining of cover size
#init of result array
resultArray = np.array(resultList)

algoWinList_1 = [0,0,0]
algoWinList_2 = [0,0,0]

#DEBUG
#print(len(resultArray[0][0]))

b = np.average(resultArray,axis=2)
b = np.around(b, decimals=2)
#print(b.shape)
j = 3

for N in range(resultArray.shape[2]):
    vcList = []

    for i in range(3):
        # resultArray[i][0][N][1] -> i is for algo (0 to 2); 0 -> is algo without "-p -r"; N -> is tested graph; [1] -> is size of VC 
        vcList.append(resultArray[i][j][N][1])

    #Compare the results -> who is winner
    minimum = min(vcList)
    maximum = max(vcList)

    numberOfWinners = 0

    for i, item in enumerate(vcList):
        if min(vcList) == item:
            numberOfWinners += 1

    for i, item in enumerate(vcList):
        if min(vcList) == item:
            algoWinList_1[i] +=1/numberOfWinners
        
            
#print(algoWinList_1 )
print(sys.argv[1])
print("[" + str(b[0][j][1]) + ","+ str(b[1][j][1]) + ","+ str(b[2][j][1]) + "]")
print("#################################")


fig_size = plt.rcParams["figure.figsize"]
fig_size[0] = 3
fig_size[1] = 3
plt.rcParams["figure.figsize"] = fig_size


#print graph
fig, ax = plt.subplots()
ind = np.arange(1, 4)


pGIC, pMDG, pME = plt.bar(ind, algoWinList_1, width=0.7)
pGIC.set_facecolor('tab:blue')
pMDG.set_facecolor('tab:orange')
pME.set_facecolor('tab:green')
ax.set_xticks(ind)
ax.set_xticklabels(['GIC', 'MDG', 'ME'])
ax.set_ylim([0, resultArray.shape[2]])
ax.set_ylabel('Počet výher algoritmu nad grafy')
ax.set_title('Hustota: ' + density )
fig.savefig("algo_" + density + ".svg")
#plt.show()




####
#