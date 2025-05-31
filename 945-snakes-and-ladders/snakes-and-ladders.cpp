class Solution {
public:
    int n;
    pair<int,int> getcoordinates(int num){
        int rb = (n-1)-(num-1)/n;
        int col = (num-1)%n;
        if((n%2==1 && rb%2==1)||(n%2==0&&rb%2==0))
        col = n-1 - col;
        return make_pair(rb,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> q;
        q.push(1);
        int steps = 0;
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        visited[n-1][0] = true;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int x = q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int i=1;i<=6;i++){
                    int val = x+i;
                    if(val > n*n) break;

                    pair<int,int> coord = getcoordinates(val);
                    int r = coord.first;
                    int c = coord.second;
                    if(visited[r][c]==true) continue;
                    visited[r][c] = true;
                    if(board[r][c]==-1) q.push(val);
                    else q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1 ;
    }
};