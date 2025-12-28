class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        """
        :type tickets: List[int]
        :type k: int
        :rtype: int
        """
        time =0
        n = len(tickets)
        for i in range(0,n):
            if(i<=k):
                time+=min(tickets[i],tickets[k])
            else:
                time+=min(tickets[i],tickets[k]-1)
        
        return time