class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        vector<int> count(1001,0);
        for(auto i: nums1){
            count[i[0]]+=i[1];
        }
        for(auto i: nums2){
            count[i[0]]+=i[1];
        }
        for(int i=0;i<1001;i++){
            if(count[i])
            res.push_back({i,count[i]});
        }
        return res;
        
    }
};