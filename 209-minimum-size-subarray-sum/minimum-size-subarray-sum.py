class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        sum=0
        n = len(nums)
        i=0
        j=0
        ans=float('inf')
        while(j<n):
            sum+=nums[j]
            while(sum>=target):
                ans = min(ans,j-i+1)
                sum-=nums[i]
                i+=1
            
            j+=1
        
        if(ans==float('inf')):
            return 0
        return ans
    