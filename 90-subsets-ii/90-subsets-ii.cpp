class Solution {
public:
    vector<vector<int>>ans;
    void f(int i,vector<int>&nums,vector<int>&curr){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
       curr.push_back(nums[i]);
        f(i+1,nums,curr);
        if(!curr.empty())curr.pop_back();
        if(i+1<=nums.size()){i++;}
        while(i<nums.size() and i>0 and nums[i]==nums[i-1]){i++;}
         f(i,nums,curr);   
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        f(0,nums,curr);
        return ans;
    }
};