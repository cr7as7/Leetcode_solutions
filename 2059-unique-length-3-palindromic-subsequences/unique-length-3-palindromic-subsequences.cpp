class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a';
            if (first[curr] == -1)
                first[curr] = i;
            last[curr] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            unordered_set<int> between;
            for (int j = first[i] + 1; j < last[i]; j++)
                between.insert(s[j]);

            ans += between.size();
        }
        return ans;
    }
};