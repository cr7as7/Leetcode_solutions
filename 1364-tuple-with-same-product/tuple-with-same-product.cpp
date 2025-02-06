class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for (auto it : mp) {
            int freq = it.second;
            count += (freq * (freq - 1) / 2) * 8;
        }
        return count;
    }
};