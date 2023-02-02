# https://leetcode.com/problems/restore-ip-addresses/

class Solution(object):
    validIPAddresses = set()

    def verifyIpAddress(self, n):

        num = n.split('.')
        while ("" in num):
            num.remove("")
        if len(num) == 4 and n.count('.') == 3:
            for i in num:
                if (int(i) > 255 or int(i) < 0) or (i[0] == '0' and int(i) != 0) or (i.count('0') == len(i) and len(i) != 1):
                    return
            self.validIPAddresses.add(n)
            return
        return

    def recurSol(self, n, index, currChar):
        if index >= len(n):
            self.verifyIpAddress(n)
            return
        while (index < len(n)):
            if (currChar <= 3):
                newStr = str(n[:index + 1] + '.' + n[index + 1:])
                self.recurSol(newStr, index + 2, 1)
            index += 1
            currChar += 1

        self.verifyIpAddress(n)

    def restoreIpAddresses(self, s):
        self.validIPAddresses.clear()
        if len(s) >= 4 and len(s) <= 12:
            self.recurSol(s, 0, 1)
        return list(self.validIPAddresses)
