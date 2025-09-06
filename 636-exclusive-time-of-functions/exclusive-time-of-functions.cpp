class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> st;
        for (auto log : logs) {
            stringstream ss(log);
            string ids, type, times;
            getline(ss, ids, ':');
            getline(ss, type, ':');
            getline(ss, times, ':');
            int id = stoi(ids);
            int time = stoi(times);
            if (type == "start")
                st.push({id, time});
            else {
                auto [startId, startTime] = st.top();
                st.pop();
                int duration = time - startTime + 1;
                res[startId] += duration;
                if (!st.empty())
                    res[st.top().first] -= duration;
            }
        }
        return res;
    }
};