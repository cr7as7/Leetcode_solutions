class Solution(object):
    def sumFourDivisors(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0

        for x in nums:
            cnt = 0
            sum = 0
            d=1
            while(d*d<=x):
                if (x % d == 0):
                    if (d * d == x):
                        cnt += 1
                        sum += d
                    else :
                        cnt += 2
                        sum += d + x / d
                    
                    if (cnt > 4): break  
                d+=1 
                
            

            if (cnt == 4):
                ans += sum
            
        

        return ans