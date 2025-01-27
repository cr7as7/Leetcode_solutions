class Solution {
public:
    unordered_map<string, bool> m;
    bool solve(string s, unordered_set<string>& se) {
        if (se.find(s) != se.end())
            return true;
        if (m.find(s) != m.end())
            return m[s];
        for (int i = 0; i < s.length(); i++) {
            string s1 = s.substr(0, i);
            if (se.find(s1) != se.end() && solve(s.substr(i), se)) {

                return m[s] = true;
            }
        }

        return m[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for (auto a : wordDict)
            se.insert(a);
        return solve(s, se);
    }
};