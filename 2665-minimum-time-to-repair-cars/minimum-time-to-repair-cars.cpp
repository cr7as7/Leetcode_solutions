class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int>& ranks, ll mid, int cars) {
        int n = ranks.size();
        ll cars_fixed = 0;
        for (int i = 0; i < n; i++) {
            cars_fixed += sqrt(mid / ranks[i]);
        }
        return cars_fixed >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int maxi = *max_element(begin(ranks), end(ranks));
        ll l = 1;
        ll r = 1LL * maxi * cars * cars;
        ll ans = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (isPossible(ranks, mid, cars)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};