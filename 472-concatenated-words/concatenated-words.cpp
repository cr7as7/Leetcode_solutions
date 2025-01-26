class Solution {
public:
    unordered_map<string,bool> mp;
    bool isConcat(string & word, unordered_set<string> & s){
        if(mp.find(word)!=mp.end())
        return mp[word];
        int l = word.length();
        for(int i=0;i<l;i++){
            string pref = word.substr(0,i+1);
            string suff = word.substr(i+1);
            if((s.find(pref)!=s.end() && s.find(suff)!=s.end())|| 
            (s.find(pref)!=s.end() && isConcat(suff,s)))
            return mp[word]= true;
        }
        return mp[word]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        mp.clear();
        unordered_set<string> s(begin(words),end(words));
        vector<string> res;
        for(int i=0;i<n;i++){
            string word = words[i];
            if(isConcat(word,s)){
                res.push_back(word);
            }
        }
        return res;
    }
};