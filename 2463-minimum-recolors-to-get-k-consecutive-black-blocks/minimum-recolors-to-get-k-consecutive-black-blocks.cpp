class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n_w=0,n=blocks.size();
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') n_w++;
        }
        int ans = n_w;
        for(int i=k;i<n;i++){
            if(blocks[i]=='W')
            n_w++;
            if(blocks[i-k]=='W')
            n_w--;
            ans = min(ans,n_w);
        }
        return ans;
    }
};