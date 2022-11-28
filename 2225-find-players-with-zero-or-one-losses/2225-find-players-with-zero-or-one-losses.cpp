class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        map<int,int>mp;
        vector<vector<int>>res(2);
        for(int i=0;i<m.size();i++){
            mp[m[i][0]];
            mp[m[i][1]];
        }
        for(int i=0;i<m.size();i++){
            mp[m[i][1]]++;
        }
        for(auto &[f,s]:mp){
            // cout<<f<<" "<<s<<endl;
            if(s==0)
                res[0].push_back(f);
            else if(s==1)
                res[1].push_back(f);
        }
        return res;
    }
};