class Solution {
public:
    void dfs(int n, int curr, vector<int> &visited, vector<vector<int>>& isConnected){
        visited[curr]=1;
        for(int i=0;i<n;i++){
            if(!isConnected[curr][i] || visited[i]) continue;
            dfs(n, i, visited, isConnected);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int connected_components=0;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            dfs(n, i, visited, isConnected);
            connected_components++;
        }
        return connected_components;
    }
};