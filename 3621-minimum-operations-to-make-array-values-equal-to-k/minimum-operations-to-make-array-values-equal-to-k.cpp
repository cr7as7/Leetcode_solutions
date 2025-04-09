class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for(auto i: nums){
            if(i < k) return -1;
            if(i > k)
            s.insert(i);
        }
        return s.size();

    }
};