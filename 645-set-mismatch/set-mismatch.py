class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        freq = [0]*(n+1)
        
        for i in nums:
            freq[i] +=1
        for i in range(1,n+1):
            if freq[i]==2:
                d=i
            if freq[i] == 0:
                m = i
        return [d,m]