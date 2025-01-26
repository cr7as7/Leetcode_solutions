class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_set<string> s;
        vector<string> state_order;
        while(n>0){
            vector<int> next(8,0);
            string currentState = "";
            for(int i=1;i<7;i++){
                next[i]=(cells[i-1]==cells[i+1]) ? 1 : 0;
            }
            for(auto i : next){
                currentState +=to_string(i);
            }
            if(s.find(currentState) !=s.end()){
                int cycleLength = s.size();
                n%=cycleLength;
                if(n==0) break;
            }
            else{
                s.insert(currentState);
                state_order.push_back(currentState);
            }
            cells = next;
            n--;
        }
        if(n>0){
            string finalState = state_order[state_order.size()-n];
            for(int i=0;i<8;i++){
                cells[i]=finalState[i]-'0';
            }
        }
        return cells;
    }
};