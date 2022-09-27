class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()){return 0;}
        if(i==nums.size()-1){return dp[i]=nums[i];}
        if(dp[i]!=-1){return dp[i];}
        int pick=nums[i]+solve(nums,i+2,dp);
        int notpick=solve(nums,i+1,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return max(solve(nums,0,dp),solve(nums,1,dp));
    }
};