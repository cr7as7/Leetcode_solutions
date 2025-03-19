class Solution {
public:
    void flip(vector<int>& nums, int p) {
        nums[p] ^= 1;
        nums[p + 1] ^= 1;
        nums[p + 2] ^= 1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 1)
                continue;
            flip(nums, i);
            res++;
        }
        if (nums[n - 1] == 1 && nums[n - 2] == 1)
            return res;

        return -1;
    }
};