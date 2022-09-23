class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX)); 
        queue<pair<int,int>> q; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()){   
            int s = q.size();
            for(int i=0;i<s;i++){
                auto p = q.front();
                q.pop();
            
                int x = p.first;
                int y = p.second;
                 
                if(x+1<n && vis[x+1][y]>vis[x][y]+1){
                    q.push({x+1,y});
                    vis[x+1][y] = vis[x][y]+1;
                }
                
                if(y+1<m && vis[x][y+1]>vis[x][y]+1){
                    q.push({x,y+1});
                    vis[x][y+1] = vis[x][y]+1;
                }
                
                if(x-1>=0 && vis[x-1][y]>vis[x][y]+1){
                    q.push({x-1,y});
                    vis[x-1][y] = vis[x][y]+1;
                }
                
                if(y-1>=0 && vis[x][y-1]>vis[x][y]+1){
                    q.push({x,y-1});
                    vis[x][y-1] = vis[x][y]+1;
                }
                
            }
            
        }
        
        return vis;

    }
};