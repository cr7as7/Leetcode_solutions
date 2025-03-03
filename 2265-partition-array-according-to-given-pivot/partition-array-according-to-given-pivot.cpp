class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();
        int i = 0, j = n - 1, start = 0, end = n - 1;
        vector<int> res(n);
        while (i < n && j >= 0) {
            if (nums[i] < pivot)
                res[start++] = nums[i];

            if (nums[j] > pivot)
                res[end--] = nums[j];
            i++;
            j--;
        }
        while (start <= end) {
            res[start++] = pivot;
        }
        return res;
    }
};