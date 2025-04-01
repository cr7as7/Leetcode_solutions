class Solution {
public:
    typedef long long ll;

    ll solve(int i, vector<vector<int>>& q, ll& n, vector<ll>& dp) {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        ll taken = q[i][0] + solve(i + q[i][1] + 1, q, n, dp);
        ll not_taken = solve(i + 1, q, n, dp);
        return dp[i] = max(taken, not_taken);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        ll n = questions.size();
        vector<ll> dp(n + 1, -1);
        return solve(0, questions, n, dp);
    }
};