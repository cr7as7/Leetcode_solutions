class Solution {
public:
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
        unordered_set<string> st;
        string ans = "";
        vector<bool> vis(tiles.size(), false);
        solve(tiles, st, ans, vis);
        return st.size();
    }
};