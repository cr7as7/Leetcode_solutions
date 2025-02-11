class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int n = s.size(),m=part.size();
        string res="";
        for(int i=0;i<n;i++){
            res.push_back(s[i]);
            if(res.length()>=m && res.substr(res.length()-m)==part){
                res.erase(res.length()-m);
            }

        }
        return res;

        
    }
};