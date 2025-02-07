class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> countOfColor;
        unordered_map<int, int> ballToColor;

        vector<int> res;
        for (auto i : queries) {
            int ball = i[0];
            int color = i[1];
            if (ballToColor.find(ball) != ballToColor.end()) {
                int prev_color = ballToColor[ball];
                countOfColor[prev_color]--;
                if (countOfColor[prev_color] == 0) {
                    countOfColor.erase(prev_color);
                }
            }
            ballToColor[ball] = color;
            countOfColor[color]++;
            res.push_back(countOfColor.size());
        }
        return res;
    }
};