class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        c=0
        ans=0
        for i in range(len(nums)):
            if nums[i]==1:
                ans +=1
            else:
                ans = 0
            c = max(ans,c)
        return c