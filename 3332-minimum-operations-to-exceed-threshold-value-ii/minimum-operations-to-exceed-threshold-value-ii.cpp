class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> minH(begin(nums),end(nums));
        
        int mini = 0;
        while (minH.size() > 1 && minH.top() < k) {
            ll x = minH.top();
            minH.pop();
            ll y = minH.top();
            minH.pop();
            minH.push(x * 2 + y);
            mini++;
        }
        return (minH.top() >= k) ? mini : -1;
    }
};