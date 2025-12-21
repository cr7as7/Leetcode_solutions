class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101,0);
        for(auto i : nums)
        count[i]++;

        for(int i=1;i<101;i++)
        count[i] +=count[i-1];
        vector<int> res;
        for(auto i: nums)
        {
            if(i==0)
            res.push_back(0);
            else
            res.push_back(count[i-1]);
        }
        return res;
    }
};