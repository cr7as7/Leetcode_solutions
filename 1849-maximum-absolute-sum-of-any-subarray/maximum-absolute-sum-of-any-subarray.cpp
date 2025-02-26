class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0,mini = INT_MAX,n=nums.size();
        int curr_sum = 0;

        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            maxi = max(maxi,curr_sum);
            if(curr_sum < 0)
            curr_sum=0;
        }
        curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            mini = min(mini,curr_sum);
            if(curr_sum > 0)
            curr_sum=0;
        }
        return max(abs(maxi),abs(mini));
    }
};