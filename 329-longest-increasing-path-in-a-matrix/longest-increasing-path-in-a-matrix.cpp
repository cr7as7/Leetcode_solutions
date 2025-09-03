class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r,
            int c) {
        int n = matrix.size();    // rows
        int m = matrix[0].size(); // cols
        if (dp[r][c] != -1)
            return dp[r][c];
        vector<int> delrow = {1, 0, -1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        int best = 1; // cell itself
        for (int i = 0; i < 4; i++) {
            int nr = delrow[i] + r;
            int nc = delcol[i] + c;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                matrix[nr][nc] > matrix[r][c])
                best = max(best, 1 + dfs(matrix, dp, nr, nc));
        }

        return dp[r][c] = best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();    // rows
        int m = matrix[0].size(); // cols
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }
};