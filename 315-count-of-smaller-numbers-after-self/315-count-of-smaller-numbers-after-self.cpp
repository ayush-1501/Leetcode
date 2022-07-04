#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 

using namespace __gnu_pbds;
 template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
     int n=nums.size();
     vector<int>ans(n,0);
     pbds<int>s;
     s.insert(nums[n-1]);
     for(int i=n-2;i>=0;i--){
       int idx=s.order_of_key(nums[i]);
	   ans[i]=idx;
	   s.insert(nums[i]);
   }
   return ans;
    }
};