class Solution {
public:
    typedef pair<int, string> P;
    string mostCommonWord(string paragraph, vector<string>& banned) {
         for (char& c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }
        unordered_map<string, int> mp;
        unordered_set<string> s;
        for (auto word : banned) {
            s.insert(word);
        }
        stringstream ss(paragraph);
        string word;
        int maxi = INT_MIN;
        string res="";
        while (ss >> word) {
            if(s.find(word)==s.end())
            mp[word]++;
            if(mp[word]>maxi)
            {
                res = word;
                maxi = mp[word];
            }
        }
        return res;
        
       
    }
};