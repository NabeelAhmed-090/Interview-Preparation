# https://leetcode.com/problems/spiral-matrix/

class Solution(object):
    def printLR(self, matrix, row, start, end, size):
        l = []
        for itr in range(start, end + 1):
            l.append(matrix[0 + row][itr])
        return l

    def printRL(self, matrix, row, start, end, size):
        l = []
        for itr in range(end, start - 1, -1):
            l.append(matrix[size - row][itr])
        return l

    def printTB(self, matrix, col, start, end, size):
        l = []
        for itr in range(start, end + 1):
            l.append(matrix[itr][size - col])
        return l

    def printBT(self, matrix, col, start, end, size):
        l = []
        for itr in range(end, start - 1, -1):
            l.append(matrix[itr][0 + col])
        return l

    def spiralOrder(self, matrix):
        rowSize = len(matrix) - 1
        colSize = len(matrix[0]) - 1
        result = []

        if colSize + 1 == 1 and rowSize + 1 == 1:
            return [matrix[0][0]]

        if colSize + 1 == 1:
            for i in matrix:
                result.append(i[0])
            return result

        if rowSize + 1 == 1:
            return matrix[0]

        itr = jStart = 0
        jEnd = colSize

        iStart = 1
        iEnd = rowSize - 1

        while (True):
            result.extend(self.printLR(matrix, itr, jStart, jEnd, rowSize))
            result.extend(self.printTB(matrix, itr, iStart, iEnd, colSize))
            if (0 + itr) < (rowSize - itr):
                result.extend(self.printRL(matrix, itr, jStart, jEnd, rowSize))
            if (itr + 0) < (colSize - itr):
                result.extend(self.printBT(matrix, itr, iStart, iEnd, colSize))
            itr += 1
            jStart += 1
            jEnd -= 1
            iStart += 1
            iEnd -= 1
            if itr > rowSize/2 or itr > colSize / 2:
                return result
