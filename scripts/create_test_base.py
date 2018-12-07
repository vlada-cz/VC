#-----------------------------------------------------------------------#
#   File: create_test_base.py
#
#   Description:    It is script for creating graphs for experminets.
#   
#   Usage:  python3.6 create_test_base.py 
#   
#   Return:     The command above will create test_base folder with
#               a lot of graphs. (Structer depand on global vars below).
#
#-----------------------------------------------------------------------#
#   Authors:    Vladimir Jerabek    <xjerab21@vutbr.cz>
#               Jan Kohut           <xkohut08@vutbr.cz>
#   
#   Date:       2018/10/24
#-----------------------------------------------------------------------#

import os
import random
import sys

#-----------------------------------------------------------------------#
#Global params -> you cen CHANGE IT
#-----------------------------------------------------------------------#

#Density number defines number of density classes
densityNum = 10

#List of vertices defines number of vertices in each density folder
vertexList = [10, 20, 30]

#Graphs number defines number of graphs in one verex folder
graphsNum = 1000

#Root directory is a path where will be created folder with test graphs
rootDir = "."
testDir = "test_base"   #name of whole test directory
densDir = "density_"    #name of each density directory -> it is in format density_x_x -> where first x is stands for number of density classes and the second x is for current density
vertDir = "vertex_size_"    #name of each vertex directory
graphName = "graph_"    #name of each graph

#relative path to graphGen -> program for generating graphs
graphGenPath = "../build/graphGen"

#get absolute path to graphGen
originPath = os.getcwd()
graphGen = os.path.join(originPath, graphGenPath)


#-----------------------------------------------------------------------#
#Function for create verticees folders with graphs
#
#args:
#   VL:     List of vertices, which will be created in density folders
#   CD:     Current density number
#   DN:     Density number is number of density classes
#   GN:     Number of graphs in each vertex folder
#-----------------------------------------------------------------------#

def createVertices(VL, CD, DN, GN):

    #create vertices folders
    for V in VL:
        vertexDir = vertDir + str(V)
        if not os.path.exists(vertexDir):
            os.makedirs(vertexDir)

        #go inside and create all graphs
        os.chdir(vertexDir)

        #number edges per density class
        EpC = round(V*(V-1)/(2*DN))

        #creating all graphs in vertex directory
        for i in range(GN):

            #number of edges
            E = random.randint(EpC*CD, EpC*(CD+1))
            #create args for command
            #e.g.: " -v 50 -e 75 graph_0 > graph_0.txt"
            graphCall = graphName + str(i)
            cmdArg = " -v " + str(V) + " -e " + str(E) + " " + graphCall + " > " + graphCall + ".txt"

            #run command and check return value
            retVal = os.system(graphGen + cmdArg)
            if (retVal != 0):
                print("Error occured: " + graphGen + cmdArg, file=sys.stderr)
                sys.exit(1)

        #go back from the vertex dir to density dir
        os.chdir("..")

#-----------------------------------------------------------------------#
#Main function
#-----------------------------------------------------------------------#

#go to root directory
os.chdir(rootDir)

#create test folder if not already exist and go there
if not os.path.exists(testDir):
    os.makedirs(testDir)

os.chdir(testDir)

#loop for all density classes
for currDens in range(densityNum):

    #create folder if it's not already created
    densFolder = densDir + str(densityNum) + "_" + str(currDens)
    if not os.path.exists(densFolder):
        os.makedirs(densFolder)

    #go into this dir
    os.chdir(densFolder)

    #create vertexes in this folder
    createVertices(vertexList, currDens, densityNum, graphsNum)

    #Go back from density folder to root folder
    os.chdir("..")

#go to back original working directory
os.chdir(originPath)
