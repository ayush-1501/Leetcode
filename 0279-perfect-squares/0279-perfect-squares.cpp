class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        int ans=INT_MAX;
        if(dp[n]!=-1)return dp[n];
        for(int i=n;i>=1;i--){
            if(n>=i*i){
                int temp=1+solve(n-i*i,dp);
                ans=min(ans,temp);
            }
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};