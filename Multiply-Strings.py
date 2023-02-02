# https://leetcode.com/problems/multiply-strings/

class Solution(object):
    def createNum(self, strNum):
        power = len(strNum) - 1
        num = 0
        for i in strNum:
            num += int(i) * pow(10, power)
            power -= 1
        return num

    def createStr(self, product):
        result = ""
        while product != 0:
            result = str(product % 10) + result
            product /= 10
        return result

    def multiply(self, num1, num2):
        if num1 == "0" or num2 == "0":
            return "0"
        product = self.createNum(num1) * self.createNum(num2)
        return self.createStr(product)
