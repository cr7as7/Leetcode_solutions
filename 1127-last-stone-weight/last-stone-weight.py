class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        pq = [-s for s in stones]
        heapq.heapify(pq)

        while(len(pq)>1):
        
            s1 = -heapq.heappop(pq)
            
            s2 = -heapq.heappop(pq)
         
            if(s1!=s2):
                heapq.heappush(pq,-(s1-s2))
        
        return 0 if not pq else -pq[0]