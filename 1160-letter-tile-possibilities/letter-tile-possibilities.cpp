class Solution {
public:
    int ans;
    void solve2(vector<int>& vec) {
        ans++;
        for (int j = 0; j < 26; j++) {
            if (vec[j]==0)
                continue;
            vec[j]--;
            solve2(vec);
            vec[j]++;
        }
        return;
    }
    void solve(string& tiles, unordered_set<string>& st, string& ans,
               vector<bool>& vis) {
        if (!ans.empty()) {
            st.insert(ans);
        }
        for (int j = 0; j < tiles.size(); j++) {
            if (vis[j])
                continue;
            vis[j] = true;
            ans += tiles[j];
            solve(tiles, st, ans, vis);
            ans.pop_back();
            solve(tiles, st, ans, vis);
            vis[j] = false;
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        // unordered_set<string> st;
        // string ans = "";
        // vector<bool> vis(tiles.size(), false);
        vector<int> vec(26,0);
        for(char ch: tiles){
            vec[ch-'A']++;
        }
        ans =0;
        // solve(tiles, st, ans, vis);
        solve2(vec);
        // return st.size();
        return ans-1;
    }
};