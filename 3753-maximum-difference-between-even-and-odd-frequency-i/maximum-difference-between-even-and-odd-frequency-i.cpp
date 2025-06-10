class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> count(26,0);
        int minie = INT_MAX, maxio = 0;
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            
        }
        for(int i=0;i<n;i++){
        if(count[s[i]-'a'] % 2 ==0&& count[s[i]-'a']!=0)
            minie = min(minie,count[s[i]-'a']);
            else if(count[s[i]-'a']%2==1)
            maxio = max(maxio,count[s[i]-'a']);
        }
        return maxio - minie;
    }
};