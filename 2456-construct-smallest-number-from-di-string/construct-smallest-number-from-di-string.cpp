class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        int count = 1;
        int n = pattern.size();
        string ans = "";
        for (int i = 0; i <= n; i++) {
            st.push(count);
            count++;
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    ans.push_back(st.top() + '0');
                    st.pop();
                }
            }
        }
        return ans;
    }
};