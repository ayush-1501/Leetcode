class Solution {
public:
    vector<pair<int,int>>dir{{0,1},{1,0},{0,-1},{-1,0}};
    int closedIsland(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        int c=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
              if((i==0 or j==0 or i==N-1 or j==M-1) and grid[i][j]==0){
                queue<pair<int,int>>q;
                q.push({i,j});
                while(!q.empty()){
                    int n=q.size();
                    while(n--){
                        pair<int,int>p=q.front();
                        q.pop();
                        grid[p.first][p.second]=1;
                        for(auto k:dir){
                            int x=p.first+k.first;
                            int y=p.second+k.second;
                            
                            if(x>=0 and x<N and y>=0 and y<M and grid[x][y]==0){
                                grid[x][y]=1;
                                q.push({x,y});
                            }
                        }
                    }
                }
              }   
            }    
        }
        

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
              if(grid[i][j]==1){continue;}
                queue<pair<int,int>>q;
                q.push({i,j});
                c++;
                while(!q.empty()){
                    int n=q.size();
                    while(n--){
                        pair<int,int>p=q.front();
                        q.pop();
                        grid[p.first][p.second]=1;
                        for(auto k:dir){
                            int x=p.first+k.first;
                            int y=p.second+k.second;
                            
                            if(x>=0 and x<N and y>=0 and y<M and grid[x][y]==0){
                                grid[x][y]=1;
                                q.push({x,y});
                            }
                        }
                    }
                }
            }    
        }  
        return c;
    }
};