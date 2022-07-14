class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,int n){
        if(j>=n or j<0){return 1e9;}
         if(i==n-1){return matrix[i][j];}
        if(dp[i][j]!=-1){return dp[i][j];}
        int down=matrix[i][j]+dfs(i+1,j,matrix,dp,n);
        int dl=matrix[i][j]+dfs(i+1,j-1,matrix,dp,n);    
        int dr=matrix[i][j]+dfs(i+1,j+1,matrix,dp,n);
        return dp[i][j]=min(down,min(dl,dr));
    
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
             vector<vector<int>>dp(n,vector<int>(n,-1));
            ans=min(ans,dfs(0,i,matrix,dp,n));
        }
        return ans;
    }
};