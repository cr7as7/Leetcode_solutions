class Solution {
public:
     int lengthLongestPath(string input) {
        stack<int> st;
        st.push(0); // dummy length for root
        int maxLen = 0;
        
        stringstream ss(input);
        string line;
        
        while(getline(ss, line, '\n')) {
            int depth = 0;
            while(line[depth] == '\t') depth++;
            
            string name = line.substr(depth);
            
            // adjust stack to correct depth
            while(st.size() > depth + 1) st.pop();
            
            int curLen = st.top() + (int)name.size() + 1;
            
            if(name.find('.') != string::npos) {
                // it's a file
                maxLen = max(maxLen, curLen - 1); // remove last '/'
            } else {
                // it's a directory
                st.push(curLen);
            }
        }
        return maxLen;
    }
};