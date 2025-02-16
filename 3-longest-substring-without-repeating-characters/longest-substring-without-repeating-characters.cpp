class Solution {
public:
    int map_func(string s, int n) {
        unordered_map<char, int> mp;
        int i = 0, j = 0, res = 0;
        while (j < n) {
            mp[s[j]]++;
            if (mp.size() == j - i + 1) {
                res = max(res, j - i + 1);
            } else {
                while (mp.size() < j - i + 1) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return res;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // return map_func(s,n);
        vector<int> hash(256, -1);
        int l = 0, r = 0, res = 0;
        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            res = max(res, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return res;
    }
};