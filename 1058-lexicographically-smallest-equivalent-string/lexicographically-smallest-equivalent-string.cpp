class Solution {
public:
    char DFS(unordered_map<char, vector<char>>& adj, vector<int>& vis, char c) {
        vis[c - 'a'] = 1;
        char mini = c;
        for (auto i : adj[c]) {
            if (!vis[i - 'a']) {
                mini = min(mini, DFS(adj, vis, i));
            }
        }
        return mini;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m = baseStr.size();
        unordered_map<char, vector<char>> adj;
        for (int i = 0; i < n; i++) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res;
        for (int i = 0; i < m; i++) {
            char c = baseStr[i];
            vector<int> vis(26, 0);
            char mini = DFS(adj, vis, c);
            res.push_back(mini);
        }
        return res;
    }
};