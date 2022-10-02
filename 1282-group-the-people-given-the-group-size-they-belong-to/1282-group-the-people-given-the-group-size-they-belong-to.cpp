class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>ans;
        for(int i=0;i<g.size();i++){
            mp[g[i]].emplace_back(i);
            
            if(mp[g[i]].size()==g[i]){
                ans.emplace_back(mp[g[i]]);
                mp[g[i]].clear();
            }
        }
        return ans;
    }
};