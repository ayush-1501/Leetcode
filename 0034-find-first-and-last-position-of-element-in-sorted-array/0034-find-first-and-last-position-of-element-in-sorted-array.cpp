class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    
        int start=0,end=nums.size()-1,mid=0;
        vector<int> ans(2,-1);
        if(nums.size()==0)
            return ans;
        while(start<=end){
            mid=end-(end-start)/2;
            if(nums[mid]==target){
                int i=mid;
                while(i>=0 && nums[i]==target){
                    i--;
                }
                i++;
                ans[0]=i;
                int j=mid;
                while(j<nums.size() && nums[j]==target){
                    j++;
                }
                j--;
                ans[1]=j;
                break;
            }
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
            
        }
        return ans;
    }
};