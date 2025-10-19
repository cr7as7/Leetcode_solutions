class Solution {
public:
// i , j 

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i=0,j=0;
        stack<int> st;
        while(i<n && j<n){
            st.push(pushed[i]);
            while(j<n && !st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};