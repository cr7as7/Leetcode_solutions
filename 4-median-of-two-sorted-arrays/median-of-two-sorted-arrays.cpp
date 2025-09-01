class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Always binary search on smaller array (nums1)
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int total = n1 + n2;
        int half = (total + 1) / 2;  // size of left partition

        int low = 0, high = n1; // binary search range on nums1

        while (low <= high) {
            int cut1 = (low + high) / 2;     // nums1's partition
            int cut2 = half - cut1;          // nums2's partition

            // Left and right values around partitions
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Valid partition found
            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 1) {
                    // odd → median is max of left part
                    return max(l1, l2);
                } else {
                    // even → median is average of max(left) and min(right)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            // Too many elements taken from nums1 → move left
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            // Too few elements taken from nums1 → move right
            else {
                low = cut1 + 1;
            }
        }
        return 0.0; // control should never reach here
    }
};