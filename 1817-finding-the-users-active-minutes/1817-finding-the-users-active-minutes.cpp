class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>>mp;
        for(int i=0;i<logs.size();++i){
           int id = logs[i][0], time = logs[i][1];
           mp[id].insert(time);
        }
         vector<int>ans(k,0);
         for(auto it: mp){
           ans[it.second.size()-1]++;
         }
        return ans;
    }
};