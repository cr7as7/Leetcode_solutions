class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> minH;
        for (auto i : nums) {
            minH.push(i);
        }
        int mini = 0;
        while (minH.top() < k || minH.empty()) {
            ll x = minH.top();
            minH.pop();
            ll y = minH.top();
            minH.pop();
            minH.push(min(x, y) * 2 + max(x, y));
            mini++;
        }
        return mini;
    }
};