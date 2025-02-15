class Solution {
public:
    bool check(string& sq, int num, int i, int currsum) {
        int n = sq.size();
        if (i == n && currsum == num)
            return true;
        else if (i == n)
            return false;

        for (int j = i; j < n; j++) {
            string s = sq.substr(i, j - i + 1);
            if (check(sq, num, j + 1, currsum + stoi(s)))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            string ss = to_string(sq);
            if (check(ss, i, 0, 0)) {
                res += sq;
            }
        }
        return res;
    }
};