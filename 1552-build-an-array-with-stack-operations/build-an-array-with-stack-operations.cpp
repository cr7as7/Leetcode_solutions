class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int idx = 0;
        for(int i=1;i<=n;i++){
            ops.push_back("Push");
            if(idx < target.size() && target[idx]==i){
                idx++;
            }else
            {
                ops.push_back("Pop");
            }
            if(idx == target.size())
            break;
        }
        return ops;
    }
};