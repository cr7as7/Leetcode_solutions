class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
     vector<int> leftMaxi(n+1,0);
     vector<int> rightMaxk(n+1,0);
     for(int j=1;j<n;j++){
        leftMaxi[j]=max(leftMaxi[j-1],nums[j-1]);
     }
     for(int j=n-2;j>=0;j--){
        rightMaxk[j]=max(rightMaxk[j+1],nums[j+1]);
     }
     long long res =0;
     for(int j=0;j<n;j++){
        res=max(res,(long long)(leftMaxi[j]-nums[j])*rightMaxk[j]);
     }  
     return res;
    }
};