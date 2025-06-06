class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minCharToRight(n);
        minCharToRight[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            minCharToRight[i]=min(s[i],minCharToRight[i+1]);
        }
        int i=0;
        string t = "";
        string paper = "";
        while(i<n){
            t.push_back(s[i]);
            char mini = (i+1<n) ? minCharToRight[i+1]: s[i];

            while(!t.empty() && t.back() <= mini){
                paper.push_back(t.back());
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            paper.push_back(t.back());
            t.pop_back();
        }
        return paper;
    }
};