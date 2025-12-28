class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c1= 0, c0=0;
        for(int i : students){
            if(i)
                c1++;
            else
                c0++;
        }
        for(int i : sandwiches){
            if(i){
                if(c1==0) break;
                c1--;
            }else{
                if(c0==0) break;
                c0--;
            }
        }
        return c1+c0;
    }
};