class Solution {
public:
    void combi(int i,vector<int>&cand,int target,set<vector<int>>&ans,vector<int>&dp){
        if(target<0 or i>=cand.size()){
            return;
        }
        if(target==0){
            ans.insert(dp);
        }
        
        dp.emplace_back(cand[i]);
        combi(i,cand,target-cand[i],ans,dp);
        dp.pop_back();
        
        combi(i+1,cand,target,ans,dp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>store;
        vector<int>dp;
        combi(0,candidates,target,store,dp);
        vector<vector<int>>result;
        for(auto i:store){
            result.emplace_back(i);
        }
        return result;
    }
};