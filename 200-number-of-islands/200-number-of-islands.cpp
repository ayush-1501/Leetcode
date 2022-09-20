class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,int N,int M){
        if(i<0 or j<0 or i>=N or j>=M or grid[i][j]=='0'){return;}
        
        grid[i][j]='0';
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int l=0;l<=3;l++){
            dfs(i+dx[l],j+dy[l],grid,N,M);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int N=grid.size();
        int M=grid[0].size();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]=='0')continue;
                 dfs(i,j,grid,N,M);
                c++;
            }
        }
        return c;
    }
};