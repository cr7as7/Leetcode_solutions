class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - k; // L in [0, n-k]

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare distances by midpoint trick:
            // if (x - arr[mid] > arr[mid + k] - x)  <=>  2*x > arr[mid] + arr[mid+k]
            if (2LL * x > 1LL * arr[mid] + 1LL * arr[mid + k]) {
                left = mid + 1;   // shift window right
            } else {
                right = mid;      // keep or shift left
            }
        }

        // Window [left, left + k)
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};