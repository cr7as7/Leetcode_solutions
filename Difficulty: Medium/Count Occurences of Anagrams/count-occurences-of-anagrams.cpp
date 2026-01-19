// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        unordered_map<char,int> mp;
        for(char ch : pat)
        mp[ch]++;
        int i=0,j=0;
        int n= txt.size();
        int ans=0,count=mp.size();
        while(j<n){
            if(mp.find(txt[j]) != mp.end()) {
                mp[txt[j]]--;
            if(mp[txt[j]] == 0)
                count--;
            }
            if(j-i+1==pat.size()){
                if(count==0)
                ans++;
                if(mp.find(txt[i]) != mp.end())
                   { if(mp[txt[i]] == 0)
                        count++;    
                    mp[txt[i]]++;
                       
                   }

              
                i++;
            }
            j++;
        }
        return ans;
    }
};