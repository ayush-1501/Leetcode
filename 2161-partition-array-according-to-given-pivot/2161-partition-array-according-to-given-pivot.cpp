class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int>ans,ans1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                ans1.push_back(nums[i]);
            }
            if(nums[i]==pivot){
                count++;
            }
        }
        vector<int>ans2;
        for(int i=0;i<ans.size();i++){
            ans2.push_back(ans[i]);
        }
        while(count--){
            ans2.push_back(pivot);
        }
        for(int i=0;i<ans1.size();i++){
            ans2.push_back(ans1[i]);
        }
        return ans2;
    }
};