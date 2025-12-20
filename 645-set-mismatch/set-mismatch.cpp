class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++)
        freq[nums[i]]++;
        int d,m;
        for(int i=1;i<=n;i++){
            if(freq[i]==2) d=i;
            if(freq[i]==0) m = i; 
        }
        return {d,m};
    }
};