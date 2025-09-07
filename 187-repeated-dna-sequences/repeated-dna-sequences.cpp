class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() < 10) return res;

        unordered_map<string,int> mp;
        for(int i=0; i<=s.length() - 10; i++){
            string sub = s.substr(i,10);
            mp[sub]++;
        }

        for(auto &p : mp){
            if(p.second > 1) res.push_back(p.first);
        }

        return res;
    }
};