class Solution {
public:
    vector<int> generateRows(int row){
        vector<int> ans;
        ans.push_back(1);
        long long val =1;
        for(int col=1;col<row;col++){
            val = val*(row-col);
            val = val/col;
            ans.push_back(val);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRows(i));
        }
        return ans;
    }
};