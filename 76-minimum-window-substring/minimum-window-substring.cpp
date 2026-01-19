class Solution {
public:
   
    string minWindow(string s, string t) {
        if ( t.size()> s.size())
        return "";
        unordered_map<char,int> mp;
        for(auto i : t)
        mp[i]++;
        int countReq = t.size();
        int n = s.size();
        int i=0,j=0,start=0;
        int miniWindowSize = INT_MAX;
        
        while(j < n){
            if(mp[s[j]]>0)
                countReq--;
            mp[s[j]]--;

            
                while(countReq == 0){
                    if( miniWindowSize >j-i+1){
                        miniWindowSize = j-i+1;
                        start =i;
                    }
                    if(mp.find(s[i]) != mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]] > 0)
                        countReq++;
                    }
                    i++;
                }
            
            j++;
        }

        if (miniWindowSize == INT_MAX) 
        return "";
        else
        return s.substr(start,miniWindowSize);
    }
};

 

