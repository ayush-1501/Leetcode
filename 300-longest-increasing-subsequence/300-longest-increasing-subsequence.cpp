class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int j=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[j]=nums[i];
            }
        }
        return ans.size();
    }
};