class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        // dp[l][r][k] = best for boxes[l..r] with k extra boxes equal to boxes[r]
        // constraints allow n up to 100 -> 100^3 ~ 1e6 states
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(boxes, 0, n - 1, 0, dp);
    }

private:
    int solve(const vector<int>& a, int l, int r, int k,
              vector<vector<vector<int>>>& dp) {
        if (l > r) return 0;
        int& memo = dp[l][r][k];
        if (memo != -1) return memo;

        int rr = r, kk = k;

        // Tail compression: merge same colors at the end into k
        while (rr > l && a[rr] == a[rr - 1]) {
            rr--;
            kk++;
        }

        // Option 1: remove the final group now
        int best = solve(a, l, rr - 1, 0, dp) + (kk + 1) * (kk + 1);

        // Option 2: try to merge a[rr] with some earlier same-colored box at i
        for (int i = l; i < rr; ++i) {
            if (a[i] == a[rr]) {
                // remove middle (i+1..rr-1) first, then merge i with rr (carry grows)
                int candidate = solve(a, l, i, kk + 1, dp) + solve(a, i + 1, rr - 1, 0, dp);
                if (candidate > best) best = candidate;
            }
        }

        return memo = best;
    }
};