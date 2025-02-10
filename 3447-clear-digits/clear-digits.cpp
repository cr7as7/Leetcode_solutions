class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans = "";
        for (auto i : s) {
            if (i >= '0' && i <= '9') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(i);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};