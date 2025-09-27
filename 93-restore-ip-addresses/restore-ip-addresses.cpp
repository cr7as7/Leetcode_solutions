class Solution {
public:
    int n;
    vector<string> res;
    bool isValid(string s){
        if(s[0]=='0') return false;
        int val = stoi(s);
        return val <=255;
    }
    void solve(string& s, int idx, int part, string curr) {
        if (idx == n && part == 4) {
            curr.pop_back();
            res.push_back(curr);
            return ;
        }
        if (idx + 1 <= n) {
            solve(s, idx + 1, part + 1, curr + s.substr(idx, 1) + '.');
        }
        if (idx + 2 <= n && isValid(s.substr(idx, 2))) {
            solve(s, idx + 2, part + 1, curr + s.substr(idx, 2) + '.');
        }
        if (idx + 3 <= n && isValid(s.substr(idx, 3))) {
            solve(s, idx + 3, part + 1, curr + s.substr(idx, 3) + '.');
        }
        return ;
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        res.clear();
        int part = 0;
        if (n > 12)
            return {};
        string curr = "";
        solve(s, 0, part, curr);
        return res;
    }
};