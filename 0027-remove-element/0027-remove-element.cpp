class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
     int idx=0;
     for(int i=0;i<nums.size();i++){
         if(nums[i]==val)
             ans++;
         else{
            nums[idx]=nums[i];
             idx++;
         }
     }
        return idx;
    }
};