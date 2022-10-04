class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        map<int,int>mp;
        for(int i:spaces){
            mp[i]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[i]){
                ans+=" ";
            }
            ans+=s[i];
        }
        return ans;
    }
};