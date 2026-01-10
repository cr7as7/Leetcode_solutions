class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if(n == 0): 
            return 0
        i = 0
        j = 1
        
        while(j < n):
            if(nums[i] != nums[j]):
                i+=1
                nums[i] = nums[j]
            j+=1
        
        
        
        return i+1