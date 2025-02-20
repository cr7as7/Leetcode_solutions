class Solution {
public:
    void solve(int n, string& curr, vector<string>& res) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }
        for (char c = 'a'; c <= 'c'; c++) {
            if (!curr.empty() && curr.back() == c)
                continue;

            curr.push_back(c);
            solve(n, curr, res);
            curr.pop_back();
        }
        return;
    }
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> res;
        solve(n, curr, res);
        if (res.size() < k)
            return "";

        return res[k - 1];
    }
};