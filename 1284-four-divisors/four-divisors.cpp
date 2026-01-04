class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int cnt = 0, sum = 0;

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    if (d * d == x) {
                        cnt += 1;
                        sum += d;
                    } else {
                        cnt += 2;
                        sum += d + x / d;
                    }
                    if (cnt > 4) break;   // early exit
                }
            }

            if (cnt == 4) {
                ans += sum;
            }
        }

        return ans;
    }
};