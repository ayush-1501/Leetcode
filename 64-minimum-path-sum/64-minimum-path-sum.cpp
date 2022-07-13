class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp,int N,int M){
        if(i==N-1 and j==M-1){return grid[i][j];}
        if(i>=N or j>=M){return 1e9;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int right=grid[i][j]+dfs(i+1,j,grid,dp,N,M);
        int down=grid[i][j]+dfs(i,j+1,grid,dp,N,M);      
        return dp[i][j]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        vector<vector<int>>dp(N,vector<int>(M,-1));
        return dfs(0,0,grid,dp,N,M);
    }
};

 // int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp,int N,int M){
 //        if(i==0 and j==0){return grid[i][j];}
 //        if(i<0 or j<0){return 1e9;}
 //        if(dp[i][j]!=-1){return dp[i][j];}
 //        int a=grid[i][j]+dfs(i-1,j,grid,dp,N,M);
 //        int b=grid[i][j]+dfs(i,j-1,grid,dp,N,M);      
 //        return dp[i][j]=min(a,b);
 //    }