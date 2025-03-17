class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> count(501,0);
        for(auto i: nums){
            count[i]++;
        }
        for(int i=0;i<501;i++){
            if(count[i]%2 !=0) return false;
        }
        return true;
    }
};