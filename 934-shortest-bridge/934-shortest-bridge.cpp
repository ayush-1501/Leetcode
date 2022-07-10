class Solution {
public:
    queue<pair<int,int>>q;
    void dfs(int i,int j,vector<vector<int>>& grid,int N,int M){
        if(i<0 or j<0 or i>=N or j>=M or grid[i][j]==0 or grid[i][j] == 2){return;}
        
        grid[i][j]=2;q.push({i,j});
        dfs(i+1,j,grid,N,M);
        dfs(i-1,j,grid,N,M);
        dfs(i,j+1,grid,N,M);
        dfs(i,j-1,grid,N,M);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        
        bool f=false;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,N,M);
                    q.push({i,j});
                    f=true;break;
                }
            }
            if(f){break;}
        }
       
         int d = 0; // dist
        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        //start the bfs
        while (!q.empty()){
            int n = q.size();
            
            while(n--){
                pair<int,int>p = q.front();
                q.pop();

                for (auto k:dir) {
                    int x =p.first+k.first;
                    int y =p.second+k.second;
                    
                    if (x>=0 and x<N && y>=0 and y<M && grid[x][y] == 1) { 
                        // if the neighbor is 1, then we return the minimum distance
                        return d;
                    }

                    else if (x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y] == 0) { 
                        // if the neighbor is 0, then mark it visited and add it to queue
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
            d++; // increasing each level by distance + 1
        }
        
        return d; // returning min dist found till end
    }
};