class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n = nums.size();
        unordered_map<int,int> mp;
        long long int ans = 0;
        for(int i = 0 ;i<n;i++){
            if(mp.find(nums[i] - i ) !=mp.end()){
                ans+=mp[nums[i]-i];
            }
            mp[nums[i]-i]++;

        }
        long long total = n*(n-1)/2;
        return total - (long long)ans;
    }
};