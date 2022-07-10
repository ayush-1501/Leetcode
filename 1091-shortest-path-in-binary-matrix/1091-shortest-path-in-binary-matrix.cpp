class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
          int n= grid.size();
        vector<vector<int>>vis(n, vector<int>(n,0));
        
        if(grid[0][0]==1)return -1;
        
        queue<pair<int,int>>q;
        int step=1,ans=1e9;
        vector<pair<int,int>>dir={{-1,-1},{-1,1},{1,-1},{1,1},{0,1},{0,-1},{1,0},{-1,0}};
        q.push({0,0});
        while(!q.empty()){
            int size= q.size();
            while(size--){
                int curi=q.front().first;
                int curj=q.front().second;
                if(curi==curj&& curi==n-1){
                    ans=min(ans,step);
                }
                q.pop();
                for(auto k:dir){
                    
                    int x=curi+k.first;
                    int y=curj+k.second;
                    if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0&& !vis[x][y]){
                        
                        vis[x][y]=1;
                        q.push({x,y});
                        
                    }
                    
                }
                
            }
            
            step++;
        }
        
        if(ans==1e9)return -1;
        return ans;
    }
};