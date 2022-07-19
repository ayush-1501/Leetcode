class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,char>mp;
        for(int i=0;i<s.size();i++){
            mp[indices[i]]=s[i];
        }
        string ans;
        for(auto i:mp){
            ans+=i.second;
        }
        return ans;
    }
};