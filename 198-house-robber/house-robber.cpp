class Solution {
public:
    int rob(vector<int>& nums) {
        int take,nontake,curr,prev=nums[0],prev2 = 0;
        for(int i=1;i<nums.size();i++){
            take=nums[i];
            if(i>1)
                take+=prev2;
            nontake=0+prev;
            curr=max(take,nontake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};