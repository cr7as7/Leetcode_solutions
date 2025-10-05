class Solution {
public:
    string convertToTitle(int N) {
        string s = "";
        while (N > 0) {
            N--;
            char c = 'A' + N % 26;
            s += c;
            N /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};