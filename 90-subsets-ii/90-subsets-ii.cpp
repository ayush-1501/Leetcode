class Solution {
public:
   set<vector<int>> s;

void solve(vector<int> nums, int i, vector<int> path){
    
    if(i == nums.size()){
        s.insert(path);
        return ;
    }
    
    
    path.push_back(nums[i]);
    solve(nums, i+1, path);
    path.pop_back();
    solve(nums, i+1, path);
    
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    
    solve(nums, 0, {});
    
    
    for(auto i : s){
        res.push_back(i);
    }
    
    return res;
 }
};