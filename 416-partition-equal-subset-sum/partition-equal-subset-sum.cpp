class Solution {
public:
    bool canPartition(vector<int>& nums) {
          sort(nums.begin(),nums.end());
        int sum=0,oo=0;;
        int i,j;
        int n=nums.size();
        for(i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        bool part[sum / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
   
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= nums[j - 1])
                part[i][j] = part[i][j]
                             || part[i - nums[j - 1]][j - 1];
        }
    }
 
    return part[sum / 2][n];
       
    }
    
};