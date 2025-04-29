class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        long long int mx = *max_element(a.begin(), a.end());
        long long int i = 0, j = 0, n = a.size();
        long long int count = 0, ans = 0;
        while (j < n) {
            if (a[j] == mx) {
                count++;
            }

            while (count >= k) {

                ans += (n - j);
                if (a[i] == mx) {
                    count--;
                }
                i++;
            }

            j++;
        }
        return ans;
    }
};