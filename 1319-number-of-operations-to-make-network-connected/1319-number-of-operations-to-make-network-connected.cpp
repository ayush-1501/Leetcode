class Solution {
public:
    void dfs(int vertex,vector<int>g[],vector<int>&vis){
        vis[vertex]=1;
        for(auto child : g[vertex]){
            if(vis[child]) continue;
            dfs(child,g,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e=connections.size();
         vector<int>g[n];
         vector<int>vis(n,0);
        if(e<n-1){return -1;}
        for(int i=0;i<e;i++){
            g[connections[i][0]].emplace_back(connections[i][1]);
            g[connections[i][1]].emplace_back(connections[i][0]); 
        }
        int c=0;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfs(i,g,vis);
                c++;
            }
        }
        
        return c-1;
    }
};