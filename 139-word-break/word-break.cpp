class Solution {
public:
    unordered_map<int, bool> m;  // memo: idx -> canBreak

    bool solve(string &s, int idx, unordered_set<string>& se) {
        int n = s.length();
        if (idx == n) return true;                 // reached end -> valid
        if (m.find(idx) != m.end()) return m[idx];

        // try every prefix starting at idx
        for (int i = idx; i < n; i++) {
            // s[idx..i]
            string pref = s.substr(idx, i - idx + 1);
            if (se.find(pref) != se.end() && solve(s, i + 1, se)) {
                return m[idx] = true;
            }
        }
        return m[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for (auto &a : wordDict) se.insert(a);
        return solve(s, 0, se);
    }
};