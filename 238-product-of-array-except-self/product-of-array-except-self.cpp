class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> pref(n), suf(n), ans(n);
        pref[0] = a[0];
        for (int i = 1; i < n; i++)
            pref[i] = a[i] * pref[i - 1];
        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = a[i] * suf[i + 1];
        ans[0] = suf[1];
        ans[n - 1] = pref[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = pref[i - 1] * suf[i + 1];
        }
        return ans;
    }
};