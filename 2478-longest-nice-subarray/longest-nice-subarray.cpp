class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, mask = 0, res = 1;
        while (j < n) {
            while ((mask & nums[j]) != 0) {
                mask = (mask ^ nums[i]);
                i++;
            }
            res = max(res, j - i + 1);
            mask = mask | nums[j];
            j++;
        }
        return res;
    }
};