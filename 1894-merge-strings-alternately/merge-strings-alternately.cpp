class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(),m =word2.size();
        string ans = "";
        int i;
        for(i=0;i<min(n,m);i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(i==n){
            for(i=n;i<m;i++)
            ans+=word2[i];
        }
        if(i==m){
            for(i=m;i<n;i++)
            ans+=word1[i];
        }
        return ans;
    }
};