class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int N,int M){
        if(i<0 or j<0 or i>=N or j>=M or grid[i][j]==0){return;}
        
        grid[i][j]=0;
        dfs(i+1,j,grid,N,M);
        dfs(i-1,j,grid,N,M);
        dfs(i,j+1,grid,N,M);
        dfs(i,j-1,grid,N,M);
    }
    int numEnclaves(vector<vector<int>>& grid) {
    
        int N=grid.size();
        int M=grid[0].size();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if((i==0 or j==0 or i==N-1 or j==M-1)and(grid[i][j]==1)){
                    dfs(i,j,grid,N,M);
                }
            }
        }
        int c=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};