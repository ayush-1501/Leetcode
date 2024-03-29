class Solution {
public:
   int f(vector<int> a, int i,vector<int>&dp){
        if(i<=1) return dp[i]=a[i];
         if(dp[i]!=-1) return dp[i];
        int pick1 =  f(a,i-1,dp);
        int pick2 = f(a,i-2,dp);
        return  dp[i]=a[i] + min(pick1,pick2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(cost.size()+1,-1);
        return min(f(cost, n-1,dp), f(cost, n-2,dp));
    }
};