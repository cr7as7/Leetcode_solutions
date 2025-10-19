class Solution {
public:
    typedef pair<int, int> P;
    // int longestSubarray(vector<int>& nums, int limit) {
    //     int n = nums.size();
    //     priority_queue<P, vector<P>> maxPq;
    //     priority_queue<P, vector<P>, greater<P>> minPq;
    //     int i = 0, j = 0, maxLength = 0;
    //     while (j < n) {
    //         maxPq.push({nums[j], j});
    //         minPq.push({nums[j], j});
    //         while (maxPq.top().first - minPq.top().first > limit) {
    //             i = min(maxPq.top().second, minPq.top().second) + 1;
    //             while (maxPq.top().second < i) {
    //                 maxPq.pop();
    //             }
    //             while (minPq.top().second < i) {
    //                 minPq.pop();
    //             }
    //         }
    //         maxLength = max(maxLength, j - i + 1);
    //         j++;
    //     }
    //     return maxLength;
    // }
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> st;
        int i = 0, j = 0, maxLength = 0;
        while (j < n) {
            st.insert(nums[j]);
            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};