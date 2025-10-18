class Solution {
public:
    vector<pair<char, int>> getGroups(const string& str) {
        vector<pair<char, int>> groups;
        for (int i = 0; i < str.size();) {
            int j = i;
            while (j < str.size() && str[j] == str[i])
                j++;
            groups.push_back({str[i], j - i});
            i = j;
        }
        return groups;
    }
    bool canBeStretched(const vector<pair<char, int>>& sGroups,
                        const string& word) {
        auto wGroups = getGroups(word);
        if (sGroups.size() != wGroups.size())
            return false;

        for (int i = 0; i < sGroups.size(); i++) {
            char sChar = sGroups[i].first;
            char wChar = wGroups[i].first;
            int sCount = sGroups[i].second;
            int wCount = wGroups[i].second;

            if (sChar != wChar)
                return false;
            if (sCount != wCount && (sCount < 3 || sCount < wCount))
                return false;
        }
        return true;
    }
    int expressiveWords(string s, vector<string>& words) {
        auto sGroups = getGroups(s);
        int stretchyCount = 0;

        for (const string& word : words)
            if (canBeStretched(sGroups, word))
                stretchyCount++;

        return stretchyCount;
    }
};