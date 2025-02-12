class Solution {
public:
    int DSUM(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        // unordered_map<int, int> mp;
        int maxi = -1;
        int mp[82]={0};
        for (auto i : nums) {
            int digitSum = DSUM(i);
            if (mp[digitSum] > 0) { //if(mp.count(digitSum)) 
                maxi = max(maxi, i + mp[digitSum]);
            }
            if (mp[digitSum] < i)
                mp[digitSum] = i;
        }
        return maxi;
    }
};