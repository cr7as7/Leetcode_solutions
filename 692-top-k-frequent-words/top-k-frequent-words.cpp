class Solution {
public:
    typedef pair<int, string> P;
    class cmp {
    public:
        bool operator()(const P& p1, const P& p2) {

            if (p1.first == p2.first)
                return p1.second < p2.second;

            return p1.first > p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto word : words) {
            mp[word]++;
        }
        priority_queue<P, vector<P>, cmp> pq;
        for (auto i : mp) {
            pq.push({i.second, i.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};