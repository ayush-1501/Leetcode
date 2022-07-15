class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int& ans,int n,int m){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)return;
         
        grid[i][j]=0;ans++;
        dfs(i+1,j,grid,ans,n,m);
        dfs(i-1,j,grid,ans,n,m);
        dfs(i,j+1,grid,ans,n,m);
        dfs(i,j-1,grid,ans,n,m);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int max_ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                int ans=0;
                dfs(i,j,grid,ans,n,m);
                max_ans=max(max_ans,ans);
            }
        }
        return max_ans;
    }
};