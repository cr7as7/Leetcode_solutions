class Solution {
public:
    int giveSumSq(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int k = giveSumSq(n);
        if (n == 1)
            return true;
        while (k != n) {
            if (k == 1)
                return true;
            k = giveSumSq(giveSumSq(k));
            n = giveSumSq(n);
        }
        return false;
    }
};