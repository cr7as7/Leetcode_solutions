class Solution(object):
    def buildArray(self, target, n):
        """
        :type target: List[int]
        :type n: int
        :rtype: List[str]
        """
        ops = []
        idx = 0
        for i in range(1,n+1):
            ops.append("Push")
            if(idx < len(target) and target[idx]==i):
                idx+=1
            else:
                ops.append("Pop")
            
            if(idx == len(target)):
                break
        
        return ops
