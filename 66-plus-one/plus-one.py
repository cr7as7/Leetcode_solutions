class Solution(object):
    def plusOne(self, digits):
        
        if not digits:
            return [1]
        n = len(digits)
        carry =1;
        
        for i in range(n-1,-1,-1):
            digits[i]+=carry
            if(digits[i] == 10):
                digits[i]=0;
            else:
                carry =0
                break
            
        
        if(carry):
            res = [0]*(n+1)
            res[0]=1
            return res
        
        else:
            return digits
            
            
      