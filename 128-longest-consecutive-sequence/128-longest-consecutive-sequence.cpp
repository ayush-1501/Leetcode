class Solution {
public:
    int dfs(unordered_map<int,int>& mp, int i){
        int res = 0;
        if(mp.find(i+1) != mp.end() && mp[i+1] == 0){
            mp[i+1] = 1;
            res += 1 + dfs(mp, i+1);
        }
        if(mp.find(i-1) != mp.end() && mp[i-1] == 0){
            mp[i-1] = 1;
            res += 1 + dfs(mp, i-1);
        }
        return res;
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 1;
        for(int i : nums) mp[i] = 0;
        for(int i: nums){
            if(mp[i] == 0) ans = max(ans, dfs(mp, i));
        }
        return nums.size()?ans:0;
    }
};