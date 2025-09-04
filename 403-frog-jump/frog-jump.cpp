#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int,int> mp; // pos -> index

    bool solve(vector<int>& stones, int jump, int idx,
               unordered_map<int,int>& mp,
               unordered_map<string,bool>& dp) {

        int n = stones.size();
        if (idx == n - 1) return true;

        string key = to_string(jump) + " " + to_string(idx);
        if (dp.find(key) != dp.end()) return dp[key];

        bool result = false;
        for (int nj = jump - 1; nj <= jump + 1; ++nj) {
            if (nj > 0) {
                int nextPos = stones[idx] + nj;
                auto it = mp.find(nextPos);
                if (it != mp.end()) {
                    if (solve(stones, nj, it->second, mp, dp)) {
                        result = true;                 // early stop
                        break;
                    }
                }
            }
        }
        return dp[key] = result;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n <= 1) return true;            // fix: single stone -> already there
        if (stones[1] != 1) return false;   // first jump must be 1

        for (int i = 0; i < n; ++i) mp[stones[i]] = i;

        unordered_map<string, bool> dp;     // fix: dp<bool>, not int
        return solve(stones, 1, 1, mp, dp);
    }
};