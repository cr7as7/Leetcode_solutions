class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans=0,c=0;
    
        for(int i=0;i<n;i++){
            if(nums[i])
            ans++;
            else 
            ans=0;
            c=max(ans,c);
        }
        return c;
        
    }
};