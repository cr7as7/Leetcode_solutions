class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int count = 0, maj = nums[0];
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                maj = nums[i];
                count++;
            } else if (maj == nums[i])
                count++;
            else
                count--;
        }
        count = 0;
        for (int i = 0; i < n; i++) {
            if (maj == nums[i])
                count++;
        }
        int fcount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj)
                fcount++;
            int lcount = count - fcount;
            int n1 = i + 1;
            int n2 = n - i - 1;
            if (fcount * 2 > n1 && lcount * 2 > n2)
                return i;
        }
        return -1;
    }
};