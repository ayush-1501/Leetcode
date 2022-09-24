class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minI=min_element(nums.begin(),nums.end())-nums.begin();
        int maxI=max_element(nums.begin(),nums.end())-nums.begin();
        if(minI>maxI){swap(minI,maxI);}
        int bothside=minI+1+n-maxI;
        int leftside=1+max(minI,maxI);
        int rightside=max(n-minI,n-maxI);
        int res=min(bothside,min(leftside,rightside));
        return res;
    }
};