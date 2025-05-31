class Solution {
public:
    void bfs(vector<int>& edges,int node,vector<bool> & visited,vector<int> & dist){
        queue<int> q;
        q.push(node);
        visited[node]= true;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            int v = edges[n];
            if(v!=-1 && !visited[v]){
                dist[v]= 1+dist[n];
                q.push(v);
                visited[v]=true;
            }
            
        }
    }
    void dfs(vector<int>& edges,int node,vector<bool> & visited,vector<int> & dist){
        visited[node]=true;
        int v = edges[node];
        if(v != -1 && !visited[v]){
            dist[v] = 1+dist[node];
            dfs(edges,v,visited,dist);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        dist1[node1]=0;
        dist2[node2]=0;
        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);
        dfs(edges,node1,visited1,dist1);
        dfs(edges,node2,visited2,dist2);
        bfs(edges,node1,visited1,dist1);
        bfs(edges,node2,visited2,dist2);
        int minNode = -1;
        int minDistTillNow = INT_MAX;
        for(int i=0;i<n;i++){
            int maxi = max(dist1[i],dist2[i]);
            if(minDistTillNow > maxi){
                minDistTillNow = maxi;
                minNode = i;
            }
        }
        return minNode;
        
        
    }
};