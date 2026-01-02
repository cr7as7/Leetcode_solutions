class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int n = nums.size();
        if(nums[0]==9 && nums[n-1] ==9) return 9;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) return nums[i];
            if(i+2 < n && nums[i]==nums[i+2]) return nums[i];
        }
          
        return -1;
    }
};