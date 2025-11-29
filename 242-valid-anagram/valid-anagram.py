class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        countS = [0]*26
        countT=[0]*26
        for c in s:
            countS[ord(c)-ord('a')]+=1
        for c in t:
            countT[ord(c)-ord('a')]+=1
        for i in range(len(countS)):
            if countS[i] != countT[i]:
                return False
        
        return True