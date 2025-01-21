class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        int front, back;
        for (int i = 0; i < n; i++) {
            int target = -nums[i];
            front = i + 1;
            back = n - 1;
            while (front < back) {
                if (nums[front] + nums[back] < target) {
                    front++;
                } else if (nums[front] + nums[back] > target)
                    back--;
                else {
                    res.push_back({nums[i], nums[front], nums[back]});
                    
                    while (front < back && nums[front] == nums[front + 1])
                        front++;
                    while(front<back && nums[back]==nums[back-1])
                    back--;
                    front++;
                    back--;

                }
                
            }
            while(i<n-1&&nums[i]==nums[i+1])
                i++;
        }
        return res;
    }
};