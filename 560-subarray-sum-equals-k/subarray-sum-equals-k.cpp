class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        mp[0] = 1;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};