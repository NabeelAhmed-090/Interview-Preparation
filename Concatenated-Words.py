# https://leetcode.com/problems/concatenated-words/

class Solution(object):
    def recur(self, word, words, minLength, maxLength):
        for i in range(1, len(word)):
            leftSub = word[0:i]
            rightSub = word[i: len(word)]
            if len(leftSub) > maxLength or len(rightSub) < minLength:
                return False
            if leftSub in words and rightSub in words:
                return True
            if leftSub in words and rightSub not in words:
                if self.recur(rightSub, words, minLength, maxLength):
                    return True
        return False

    def findAllConcatenatedWordsInADict(self, words):
        unique_words = set(words)
        minLength = len(min(unique_words, key=len))
        maxLength = len(max(unique_words, key=len))

        return [word for word in unique_words if self.recur(word, unique_words, minLength, maxLength)]
