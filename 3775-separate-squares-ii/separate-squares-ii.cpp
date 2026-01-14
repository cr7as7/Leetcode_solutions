#include <bits/stdc++.h>
using namespace std;

struct Event {
    double y;
    double x1, x2;
    int type; // +1 add, -1 remove
};

struct SegTree {
    vector<int> cover;
    vector<double> len;
    vector<double>& xs;

    SegTree(int n, vector<double>& xs) : xs(xs) {
        cover.assign(4*n, 0);
        len.assign(4*n, 0);
    }

    void push(int node, int l, int r) {
        if (cover[node] > 0)
            len[node] = xs[r+1] - xs[l];
        else if (l == r)
            len[node] = 0;
        else
            len[node] = len[node*2] + len[node*2+1];
    }

    void update(int node, int l, int r, int ql, int qr, int v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            cover[node] += v;
            push(node, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(node*2, l, m, ql, qr, v);
        update(node*2+1, m+1, r, ql, qr, v);
        push(node, l, r);
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<double> xs;

        for (auto& s : squares) {
            double x1 = s[0], x2 = s[0] + s[2];
            double y1 = s[1], y2 = s[1] + s[2];

            events.push_back({y1, x1, x2, +1});
            events.push_back({y2, x1, x2, -1});
            xs.push_back(x1);
            xs.push_back(x2);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](double x) {
            return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        };

        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a.y < b.y; });

        SegTree st(xs.size(), xs);

        double totalArea = 0;
        for (int i = 0; i + 1 < events.size(); i++) {
            int l = getX(events[i].x1);
            int r = getX(events[i].x2) - 1;
            st.update(1, 0, xs.size()-2, l, r, events[i].type);

            double dy = events[i+1].y - events[i].y;
            totalArea += st.len[1] * dy;
        }

        double half = totalArea / 2;
        st.cover.assign(4*xs.size(), 0);
        st.len.assign(4*xs.size(), 0);

        double curArea = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            int l = getX(events[i].x1);
            int r = getX(events[i].x2) - 1;
            st.update(1, 0, xs.size()-2, l, r, events[i].type);

            double dy = events[i+1].y - events[i].y;
            double strip = st.len[1] * dy;

            if (curArea + strip >= half) {
                double remain = half - curArea;
                return events[i].y + remain / st.len[1];
            }
            curArea += strip;
        }

        return events.back().y;
    }
};