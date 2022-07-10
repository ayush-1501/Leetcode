class Solution {
public:
    int area=0;
    void dfs(int i,int j,vector<vector<int>>& grid,int N,int M){
        if(i<0 or j<0 or i>=N or j>=M or grid[i][j]==0){return;}
        
        grid[i][j]=0;area++;
        dfs(i+1,j,grid,N,M);
        dfs(i,j+1,grid,N,M);
        dfs(i-1,j,grid,N,M);
        dfs(i,j-1,grid,N,M);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m_area=0;
        int N=grid.size();
        int M=grid[0].size();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                area=0;
                dfs(i,j,grid,N,M);
                m_area=max(area,m_area);
            }
        }
        return m_area;
    }
};