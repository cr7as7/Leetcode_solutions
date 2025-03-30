class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> cnt(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a'] = i;
        }
        vector<int> res;
        int size = 0, end = 0;
        for (int i = 0; i < n; i++) {
            size++;
            end = max(end, cnt[s[i] - 'a']);
            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};