class Solution {
public:
    int bsearch(vector<int>&nums,int t,bool val){
        int s=0;
        int e=nums.size()-1;
        int f=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==t){
                f=m;
                if(val){
                    s=m+1;
                }
                else{
                    e=m-1;
                }
                continue;
                
            }
            else if(nums[m]<t)
                s=m+1;
            else 
                e=m-1;
        }
        return f;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f1=bsearch(nums,target,0);
        int f2=bsearch(nums,target,1);
        return {f1,f2};
    }
};