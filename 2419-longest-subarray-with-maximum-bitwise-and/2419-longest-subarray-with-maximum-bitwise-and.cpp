class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int t=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int j=0;
            while(nums[i]==t and i<nums.size()){
                i++;j++;
                ans=max(ans,j);
                if(i==nums.size()){break;}
            }
        }
      return ans;
    }
};