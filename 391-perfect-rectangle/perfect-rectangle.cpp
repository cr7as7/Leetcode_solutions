class Solution {
public:
    string make_key(int x, int y) { return to_string(x) + "#" + to_string(y); }
    void toggle(unordered_set<string>& s, int x, int y) {
        string k = make_key(x, y);
        if (s.count(k))
            s.erase(k);
        else
            s.insert(k);
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> s;
        long long totalArea = 0;
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        for (auto r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            totalArea += 1LL * (x2 - x1) * (y2 - y1);
            minx = min(minx, x1);
            miny = min(miny, y1);
            maxx = max(maxx, x2);
            maxy = max(maxy, y2);

            toggle(s, x1, y1);
            toggle(s, x2, y2);
            toggle(s, x1, y2);
            toggle(s, x2, y1);
        }
        if (s.size() != 4)
            return false;
        if (!s.count(make_key(minx, miny)) || !s.count(make_key(minx, maxy)) ||
            !s.count(make_key(maxx, miny)) || !s.count(make_key(maxx, maxy)))
            return false;
        long long bigArea = 1ll * (maxx - minx) * (maxy - miny);
        return totalArea == bigArea;
    }
};