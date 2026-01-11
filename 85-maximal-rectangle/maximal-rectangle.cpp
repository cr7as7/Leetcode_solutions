class Solution {
public:
 vector<int> NSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = n;
        vector<int> right(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }
        vector<int> NSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int pseudo_index = -1;
        vector<int> left(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {
                while(!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if(st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }
    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = NSR(heights);
        vector<int> left  = NSL(heights);
        vector<int> width(n);
        for(int i = 0; i<n; i++)
            width[i] = right[i]-left[i]-1;
        int max_area = 0;
        
        for(int i = 0; i<n; i++) {
            int a =  width[i]*heights[i];
            if(max_area < a)
                max_area = a; 
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
               int maxArea = 0;
        int m       = matrix.size();
        int n       = matrix[0].size();

          vector<int> heights(n, 0);
        for(int col = 0; col < n; col++) {
            heights[col] = matrix[0][col] == '0' ? 0 : 1;
        }

         maxArea = MAH(heights);

           for(int row = 1; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col] += 1;
                }
            }
            
            maxArea = max(maxArea, MAH(heights));
        }
        
        return maxArea;

        
    }
};