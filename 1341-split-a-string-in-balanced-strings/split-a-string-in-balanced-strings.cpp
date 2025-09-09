class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int balance = 0;
        
        for (char ch : s) {
            if (ch == 'L') balance++;
            else if (ch == 'R') balance--;

            if (balance == 0) count++;
        }
        
        return count;
    }
};