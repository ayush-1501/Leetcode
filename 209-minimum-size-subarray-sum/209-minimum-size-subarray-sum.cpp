class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int ans=INT_MAX,sum=0;
        for(int i=0,j=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                sum-=nums[j];
                ans=min(ans,i-j+1);
                j++;
            }
        }
        if(ans==INT_MAX){return 0;}
        return ans;
    }
};