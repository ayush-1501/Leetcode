class Solution {
public:
  int solve(int idx, int n, vector<int>&nums,vector<int>&dp){
        if(idx >= n) return 0;
        if(idx==nums.size()-1){return dp[idx]=nums[idx];}
        if(dp[idx]!=-1){return dp[idx];}
        return dp[idx]=max(nums[idx] + solve(idx+2,n,nums,dp), solve(idx+1,n,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp1(nums.size(),-1),dp2(nums.size(),-1);
        return max(solve(0,n-1,nums,dp1), solve(1,n,nums,dp2));
    }
};