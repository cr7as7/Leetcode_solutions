class Solution {
public:
    void inplace(string & s){
        int ans_len=0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                ans_len = max(ans_len - 1,0);
            }
            else{
                s[ans_len] = s[i];
                ans_len++;
            }
        }
        s.resize(ans_len);

    }
    string clearDigits(string s) {
        inplace(s);
        return s;

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