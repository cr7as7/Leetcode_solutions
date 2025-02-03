class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        
        int incCnt = 1, decCnt = 1, maxLen = 1;
        
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                incCnt++;
                decCnt = 1;  
            } 
            else if (a[i] < a[i - 1]) {
                decCnt++;
                incCnt = 1; 
            } 
            else {
                incCnt = decCnt = 1;
            }

            maxLen = max(maxLen, max(incCnt, decCnt));
        }

        return maxLen;
    }
};