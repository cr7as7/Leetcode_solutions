class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if (s1 == s2)
            return true;
        int cnt = 0, idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i] && idx1 == -1) {
                idx1 = i;
            }
            if (s1[i] != s2[i] && idx1 != -1) {
                idx2 = i;
            }
        }
        if (idx1 != -1 && idx2 != -1) {
            swap(s2[idx1], s2[idx2]);
            return (s1 == s2);
        }
        return false;
    }
};