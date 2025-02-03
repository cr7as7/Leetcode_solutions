class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int incCnt=0,decCnt=0,maxi = INT_MIN,mini = INT_MIN;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(i==0||(i>0 && a[i]==a[i-1])){
                incCnt=1;
                decCnt = 1;
                maxi = max(maxi,incCnt);
                mini = max(mini,decCnt);
            }
            if(i>0 && a[i]>a[i-1]){
                incCnt++;
                decCnt =1;
                maxi = max(maxi,incCnt);
            }
            if(i>0 && a[i]<a[i-1]){
                decCnt++;
                incCnt=1;
                mini = max(mini,decCnt);
            }
            
        }
        return max(maxi,mini);
    }
};