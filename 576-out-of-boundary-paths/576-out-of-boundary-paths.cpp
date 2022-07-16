class Solution {
public:
    const int mod=1e9+7;
     long long dfs(int i, int j, int n, int m, int moves,vector<vector<vector<int>>>&dp){        
        if(i<0 or i>= n or j<0 or j >= m){return 1;}
        if(moves <= 0){return 0;}
         if(dp[i][j][moves]!=-1){return dp[i][j][moves];}
        long long up = dfs(i - 1, j, n, m, moves - 1,dp);
        long long down = dfs(i + 1, j, n, m, moves - 1,dp);
        long long left = dfs(i, j - 1, n, m, moves - 1,dp);
        long long right = dfs(i, j + 1, n, m, moves - 1,dp);
        
        return dp[i][j][moves]=(up%mod+down%mod+left%mod+right%mod)%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(55,-1)));
        int ans=0;
        ans=dfs(startRow,startColumn,m,n,maxMove,dp);
        return ans;
    }
};