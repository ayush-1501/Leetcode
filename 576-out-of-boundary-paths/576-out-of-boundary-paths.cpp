class Solution {
public:
   int mod = 1000000007;
    long long dfs(int row,int col,vector<vector<vector<int>>>&dp,int t,int m,int n){
        if(row<0 || col<0 || row>=m || col>=n) return 1;
        if(t==0) return 0;
        if(dp[row][col][t]!=-1) return dp[row][col][t];
        long long left= dfs(row,col-1,dp,t-1,m,n);
        long long right= dfs(row,col+1,dp,t-1,m,n);
        long long up=dfs(row+1,col,dp,t-1,m,n);
        long long down= dfs(row-1,col,dp,t-1,m,n);
        return dp[row][col][t] = (left%mod+right%mod+up%mod+down%mod)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int row, int col) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (maxMove+1,-1)));
        return dfs(row,col,dp,maxMove,m,n)%mod;
    }
};