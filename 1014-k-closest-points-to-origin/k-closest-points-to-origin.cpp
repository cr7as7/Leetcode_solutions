class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P> maxh;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int dist =
                points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pair<int, pair<int, int>> p = {dist, {points[i][0], points[i][1]}};
            maxh.push(p);
            if (maxh.size() > k) {
                maxh.pop();
            }
        }
        vector<vector<int>> res;
        while (!maxh.empty()) {
            pair<int, pair<int, int>> p = maxh.top();
            res.push_back({p.second.first, p.second.second});
            maxh.pop();
        }
        return res;
    }
};