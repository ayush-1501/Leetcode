#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 

using namespace __gnu_pbds;
 template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
          int n=nums.size();
          vector<int>ans(n,0);
          pbds<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int t=s.order_of_key(nums[i]);
            ans[i]=t;
        }
        return ans;
    }
};