class Solution {
public:
    string gen(string word){
        vector<int> c(26,0);
        int n = word.size();
        for(int i = 0;i<n;i++){
            c[word[i]-'a']++;
        }
        string s="";
        for(int i=0;i<26;i++){
            if(c[i]){
                s+=string(c[i],i+'a');
            }
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string new_word = gen(strs[i]);
            mp[new_word].push_back(strs[i]);
        }
        for(auto i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};