class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        // Step 1: center must be 5
        if (g[r+1][c+1] != 5) return false;

        // Step 2: values 1..9 and distinct
        vector<bool> seen(10, false);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9 || seen[v]) return false;
                seen[v] = true;
            }
        }

        // Step 3: check sums
        int sum = g[r][c] + g[r][c+1] + g[r][c+2];

        for (int i = r; i < r + 3; i++) {
            if (g[i][c] + g[i][c+1] + g[i][c+2] != sum)
                return false;
        }

        for (int j = c; j < c + 3; j++) {
            if (g[r][j] + g[r+1][j] + g[r+2][j] != sum)
                return false;
        }

        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum)
            return false;

        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isMagic(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};