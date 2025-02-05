class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // Already equal
        
        int idx1 = -1, idx2 = -1, diffCount = 0;
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffCount++;
                if (idx1 == -1) idx1 = i;
                else if (idx2 == -1) idx2 = i;
                else return false; // More than 2 differences → cannot be fixed with 1 swap
            }
        }
        
        return (diffCount == 2 && s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1]);
    }
};