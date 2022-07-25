class Solution {
public:
    int firstIdx(vector<int> nums,int target){
        int idx = -1;
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                idx = mid;
                end=mid-1;
            }
            else if(nums[mid]<target) start=mid+1;
            else end=mid-1;
        }
        return idx;
        
        
    }
    int lastIdx(vector<int> nums,int target){
        int idx = -1;
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                idx = mid;
                start=mid+1;
            }
            else if(nums[mid]<target) start=mid+1;
            else end=mid-1;
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstIdx(nums,target);
        int last=lastIdx(nums,target);
        
        return {first,last};
    }     
};