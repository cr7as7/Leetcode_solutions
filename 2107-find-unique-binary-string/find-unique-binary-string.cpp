class Solution {
public:
    string ans = "";
    void solve(int n, string& curr, unordered_set<string>& s) {
        if (curr.size() == n && s.find(curr) == s.end()) {
            ans = curr;
            return;
        }
        if (curr.size() == n)
            return;
        for (char c = '0'; c <= '1'; c++) {
            curr.push_back(c);
            solve(n, curr, s);
            curr.pop_back();
        }
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        int n = nums[0].size();
        string curr = "";
        solve(n, curr, s);
        return ans;
    }
};