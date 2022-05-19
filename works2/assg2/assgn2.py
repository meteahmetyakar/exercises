import numpy as np
import random
import sys


#### QII ####

def readMatrix(numberOfRows, numberOfColumns, file):
    matrix = []  # Create an empty list
    for row in range(numberOfRows):
        matrix.append([])  # Add an empty new row
        line = file.readline()
        rowdata = [int(x) for x in line.split(' ')]
        for column in range(numberOfColumns):
            matrix[row].append(rowdata[column])
    return matrix


def printMatrix(matrix):
    for row in range(len(matrix)):
        for column in range(len(matrix[row])):
            print(format(matrix[row][column], "5d"), end=" ")
        print()  # Print a new line


def fillMatrixRandomly(numberOfRows, numberOfColumns):
    matrix = []  # Create an empty list
    for row in range(numberOfRows):
        matrix.append([])  # Add an empty new row
        for column in range(numberOfColumns):
            matrix[row].append(random.randint(0, 99))
    return matrix

def generateZeroMatrix(numberOfRows, numberOfColumns):
    matrix = [[0 for i in range(numberOfRows)] for j in range(numberOfColumns)]
    return matrix

def addMatrix(A, B):
    C = generateZeroMatrix(len(A), len(A[0]))
    for row in range(len(A)):
        for column in range(len(A[row])):
            C[row][column] = A[row][column] + B[row][column]

    return C

def subtractMatrix(A,B):
    C = generateZeroMatrix(len(A), len(A[0]))
    for row in range(len(A)):
        for column in range(len(A[row])):
            C[row][column] = A[row][column] + B[row][column]
    return C

def maxOfElements(A):
    max_val=A[0][0]
    for i in range(len(A)):
        for j in range(len(A[i])):
            max_val=max(max_val,A[i][j])
    return max_val

def transpose(A):
    B=generateZeroMatrix(len(A),len(A[0]))
    for i in range(len(A)):
        for j in range(len(A[i])):
            B[i][j]=A[j][i]
    return B

def multiplyMatrix(A, B):
    C=generateZeroMatrix(len(A),len(B[0]))
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]
    return C






# Redirect standard output device (console) to output.txt file
# print statements will write into output.txt file

print("\nReading data from inputs.txt file in current directory\n")
f = open("inputs.txt", "r")

# Read Matrix A
line = f.readline()

numberOfRows, numberOfColumns = [int(x) for x in line.split(' ')]
A = readMatrix(numberOfRows, numberOfColumns, f)
print(" **** Matrix A **** ")
printMatrix(A)

# Read Matrix B
line = f.readline()
numberOfRows, numberOfColumns = [int(x) for x in line.split(' ')]
B = readMatrix(numberOfRows, numberOfColumns, f)
print(" **** Matrix B **** ")
printMatrix(B)
# Read Matrix C
line = f.readline()
numberOfRows, numberOfColumns = [int(x) for x in line.split(' ')]
C = readMatrix(numberOfRows, numberOfColumns, f)
print(" **** Matrix C **** ")
printMatrix(C)

# Generate 4x4 matrix from random numbers.
D = fillMatrixRandomly(numberOfRows, numberOfColumns)
print(" **** Matrix D **** ")
printMatrix(D)

# Compute S = (A+B) * Transpose(C) + D - A
print("\n *** Computing S = (A+B) * Transpose(C) + D) - A *** \n")

# T1 = A + B
T1 = addMatrix(A, B)

print(" **** MatriX T1 = (A+B) ****")
printMatrix(T1)
# T2 = Transpose(C)
T2= transpose(C)
print("**** Matrix T2 = Transpose(C) ****")
printMatrix(T2)
# T3 = ( A + B )* transpose( C )
T3=multiplyMatrix(T1,T2)
print("**** Matrix T3 =(A+B) * transpose(C) ****")
printMatrix(T3)
# T4 =( A + B )* transpose( C ) + D
T4=addMatrix(T3,D)
print("**** Matrix T4 =(A+B) * transpose(C)+ D ****")
printMatrix(T4)
# S = ( A + B )* transpose( C ) + D -A
S=subtractMatrix(T4,A)
print("**** Matrix S =(A+B) * transpose(C) + D - A ****")
printMatrix(S)
max_val=maxOfElements(S)
print("Maximum Element in S = {} ".format(max_val))
