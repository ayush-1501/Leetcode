class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
             if(nums[i]<0){
                 mp[nums[i]]++;
             }else if(mp[-nums[i]]){ans.emplace_back(nums[i]);}
        }
        int t=-1;
        for(auto i:ans){
                t=i;
        }
        return t;
    }
};