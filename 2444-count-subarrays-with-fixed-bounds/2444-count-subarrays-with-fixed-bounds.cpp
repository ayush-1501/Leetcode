class Solution {
public:
    using ll = long long;
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int n = nums.size();
        set<int> block_idx;
        set<int> min_idx;
        set<int> max_idx;
        for(int i=0;i<n;++i){
            if(nums[i] < minK || nums[i] > maxK){
                block_idx.insert(i);
            }
            if(nums[i] == minK){
                min_idx.insert(i);
            }
            if(nums[i] == maxK){
                max_idx.insert(i);
            }
        }
        if(min_idx.empty() || max_idx.empty()){
            return 0;
        }
        // block_idx.insert(-1);
        block_idx.insert(n);
        ll result = 0;
        for(int i=0;i<n;++i){
            auto it_min = min_idx.lower_bound(i);
            if(it_min == min_idx.end()){
                continue;
            }
            auto it_max = max_idx.lower_bound(i);
            if(it_max == max_idx.end()){
                continue;
            }
            int start_i = max(*it_min, *it_max);
            auto it_block = block_idx.lower_bound(i);
            int end_i = *it_block;
            result += ll(max(end_i - start_i, 0));
        }
        return result;
    }
};