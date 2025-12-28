class Solution(object):
    def countStudents(self, students, sandwiches):
        """
        :type students: List[int]
        :type sandwiches: List[int]
        :rtype: int
        """
        c1= 0
        c0=0 
        for i in students:
            if(i):
                c1+=1
            else:
                c0+=1
        for i in sandwiches:
            if(i):
                if c1==0: 
                    break
                c1-=1
            else:
                if c0==0: 
                    break
                c0-=1
            
        return c1+c0