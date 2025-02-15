class Solution {
public: // sq,idx,sum
    unordered_map<int, unordered_map<int, bool>> mp;
    bool check(string& sq, int num, int i, int currsum) {
        int n = sq.size();
        if (i == n && currsum == num)
            return mp[i][currsum] = true;
        else if (i == n)
            return mp[i][currsum] = false;
        if (mp[i].count(currsum))
            return mp[i][currsum];
        for (int j = i; j < n; j++) {
            string s = sq.substr(i, j - i + 1);
            if (check(sq, num, j + 1, currsum + stoi(s)))
                return mp[i][currsum] = true;
        }
        return mp[i][currsum] = false;
    }
    int punishmentNumber(int n) {
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            mp.clear();
            string ss = to_string(sq);
            if (check(ss, i, 0, 0)) {
                res += sq;
            }
        }
        return res;
    }
};