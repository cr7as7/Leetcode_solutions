class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastInd = 0;
        int maxi = -1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(a[i]%a[j] == 0 && dp[i]< dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }

            }
            if(dp[i]> maxi)
            {
                maxi=dp[i];
                lastInd = i;
            }
        }
        vector<int> temp;
        temp.push_back(a[lastInd]);
        while(hash[lastInd] != lastInd){
            lastInd = hash[lastInd];
            temp.push_back(a[lastInd]);
        }
        return temp;
    }
};