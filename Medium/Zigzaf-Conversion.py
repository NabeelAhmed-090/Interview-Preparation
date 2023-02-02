# https://leetcode.com/problems/zigzag-conversion/

class Solution(object):
    list_of_num = []

    def fillColoumn(self, s, index, numRows, colIndex):
        for itr in range(0, numRows):
            self.list_of_num[itr][colIndex] = s[index]
            index += 1
            if index == len(s):
                return index
        return index

    def fillDiagonal(self, s, index, numRows, colIndex):
        row = numRows - 2
        cols = colIndex
        while row > 0:
            self.list_of_num[row][cols] = s[index]
            row -= 1
            cols += 1
            index += 1
            if index == len(s) or row == 0:
                return cols, index

        return cols, index

    def initializeLists(self, numRows, numCols, size):
        self.list_of_num = [
            [-1 for x in range(size)] for y in range(numRows)]

    def extractString(self, numRows, numCols):
        outputString = ""
        for i in self.list_of_num:
            for j in i:
                if j != -1:
                    outputString += j
        return outputString

    def convert(self, s, numRows):
        numCols = numRows - 2
        self.initializeLists(numRows, numCols, len(s))
        rowIndex = colIndex = index = 0
        while index < len(s):
            index = self.fillColoumn(s, index, numRows, colIndex)
            if index < len(s):
                colIndex += 1
                colIndex, index = self.fillDiagonal(
                    s, index, numRows, colIndex)
        return self.extractString(numRows, numCols)
