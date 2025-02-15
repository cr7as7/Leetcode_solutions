class Solution {
public: // sq,idx,sum
    bool check(string& sq, int num, int i, int currsum,
               vector<vector<int>>& t) {
        if (currsum > num)
            return false;
        int n = sq.size();
        if (i == n)
            return currsum == num;
        else if (i == n)
            return t[i][currsum] = false;

        if (t[i][currsum] != -1)
            return t[i][currsum];
        for (int j = i; j < n; j++) {
            string s = sq.substr(i, j - i + 1);
            if (check(sq, num, j + 1, currsum + stoi(s), t))
                return t[i][currsum] = true;
        }
        return t[i][currsum] = false;
    }
    int punishmentNumber(int n) {
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int sq = i * i;

            string ss = to_string(sq);
            vector<vector<int>> t(ss.length(), vector<int>(i + 1, -1));
            if (check(ss, i, 0, 0, t)) {
                res += sq;
            }
        }
        return res;
    }
};