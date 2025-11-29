class Solution(object):
    def isVowel(self,c):
        if c == 'a' or c == 'A' or c == 'e' or c == 'E' or c == 'i' or c == 'I' or c == 'o' or c == 'O' or c == 'u' or c == 'U':
            return True
        else:
            return False
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = []
        for c in s:
            if self.isVowel(c):
                res.append(c)
        res.reverse()
        j =0
        newS = ""
        for i in range(len(s)):
            if self.isVowel(s[i]):
                newS += res[j]
                j+=1
            else:
                newS+=s[i]
        return newS