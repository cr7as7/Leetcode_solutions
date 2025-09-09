class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> row(3, 0), col(3, 0);
        int diag = 0, anti_diag = 0;
        int player = 1;  // A -> +1, B -> -1

        for (auto& move : moves) {
            int r = move[0], c = move[1];
            row[r] += player;
            col[c] += player;

            if (r == c) diag += player;
            if (r + c == 2) anti_diag += player;

            // Check win
            if (abs(row[r]) == 3 || abs(col[c]) == 3 ||
                abs(diag) == 3 || abs(anti_diag) == 3) {
                return player == 1 ? "A" : "B";
            }

            player *= -1; // Toggle between A (+1) and B (-1)
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};