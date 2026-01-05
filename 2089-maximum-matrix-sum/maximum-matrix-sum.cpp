class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        long long int c = 0, sum = 0, n = a.size(), m = a[0].size(), mini = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += abs(a[i][j]);
                mini = min(mini, (long long) llabs(a[i][j]));
                if (a[i][j] < 0)
                    c++;
            }
        }
        if (c % 2)
            sum -= 2*mini;
        return sum;
    }
};