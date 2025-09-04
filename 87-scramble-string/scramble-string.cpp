class Solution {
public:
    unordered_map<string, bool> dp;
    bool solve(string s1, string s2) {
        string key = s1 + "_" + s2;
        if(dp.find(key)!=dp.end()) return dp[key];
        if (s1 == s2)
            return dp[key]=true;
        if (s1.length() != s2.length())
            return dp[key]=false;
        bool res = false;
        int n = s1.length();
        for (int i = 1; i < n; i++) {
            bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i)) &&
                           solve(s1.substr(i, n - i), s2.substr(0, n - i));
            if (swapped) {
                res = true;
                break;
            }
            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
                               solve(s1.substr(i, n - i), s2.substr(i, n - i));
            if (not_swapped) {
                res = true;
                break;
            }
        }
        return dp[key]=res;
    }
    bool isScramble(string s1, string s2) { return solve(s1, s2); }
};