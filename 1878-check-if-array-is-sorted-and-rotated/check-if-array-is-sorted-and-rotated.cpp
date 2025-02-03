class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        int seriesBreak = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                seriesBreak++;
            }
        }
        if (a[n - 1] > a[0]) {
            seriesBreak++;
        }

        return seriesBreak <= 1;
    }
};