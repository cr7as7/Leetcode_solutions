class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0,r=0,n=nums.size(),maxi= INT_MIN,nzero=0;
        while(r<n){
            if(nums[r]==1){
                maxi = max(maxi,r-l+1);
            }
            else if(nums[r]==0){
                nzero++;
                while(nzero > k){
                    if(nums[l]==1)
                    {
                        l++;
                    }else {
                        nzero--;
                        l++;
                    }
                }
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};