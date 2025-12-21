class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:

        count = [0]*101
        for i in nums:
            count[i]+=1

        for i in range(1,101):
            count[i] +=count[i-1]
        res = []
        for i in nums:
            if i == 0:
                res.append(0)
            else:
                res.append(count[i-1])
        return res
    
