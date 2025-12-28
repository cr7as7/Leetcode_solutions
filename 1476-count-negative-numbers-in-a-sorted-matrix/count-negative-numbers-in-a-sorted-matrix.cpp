class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        for(int i=0;i<n;i++){
            int l =0,r=m-1,idx=-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(grid[i][mid]<0)
                {
                        idx = mid;
                        r=mid-1;
                }
                else if(grid[i][mid]>=0)
                    l=mid+1;
                
            }
            if(idx != -1)
                c+=m-idx;
        }
        return c;
    }
};