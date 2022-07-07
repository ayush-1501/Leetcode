#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 

using namespace __gnu_pbds;
 template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        pbds<double>s;
        int t=0;
        for(int i=nums.size()-1;i>=0;i--){
            t+=s.order_of_key(nums[i]/2.0);
            s.insert(nums[i]);
        }
        for(auto i:s){cout<<i<<" ";}
        return t;
    }
};