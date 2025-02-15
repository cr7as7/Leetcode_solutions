class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0, maxi = INT_MIN, ridx = n - 1;
        for (int i = 0; i <= k - 1; i++) {
            lsum += cardPoints[i];
        }
        maxi = lsum;
        for (int i = k - 1; i >= 0; i--) {
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[ridx--];
            maxi = max(maxi, lsum + rsum);
        }
        return maxi;
    }
};