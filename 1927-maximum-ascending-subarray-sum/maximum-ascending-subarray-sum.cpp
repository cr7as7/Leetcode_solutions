class Solution {
public:
    int maxAscendingSum(vector<int>& a) {
        int n = a.size();
        int sum = a[0], currsum = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1])
                currsum += a[i];
            else
                currsum = a[i];
            sum = max(sum, currsum);
        }
        return sum;
    }
};