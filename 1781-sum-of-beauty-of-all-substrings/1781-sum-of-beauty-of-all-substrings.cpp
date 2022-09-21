class Solution {
public:
    int beautySum(string s) {
       int ans=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp.clear();
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                int max_mp=0;
                int min_mp=500;
                for(auto i:mp){
                    max_mp=max(max_mp,i.second);
                    min_mp=min(min_mp,i.second);
                }
                ans+=max_mp-min_mp;
            }
        }
        return ans;
    }
};