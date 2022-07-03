class Solution {
public:
    string decodeMessage(string key, string message) {
       unordered_map<char,char>mp;
        char alpha='a';
       for(auto i:key){
           if(i==' '){continue;}
           else if(mp.count(i))continue;
           else mp[i]=alpha++;
       }
        for(auto i:mp){cout<<i.first<<" "<<i.second<<" \n";}
        string ans;
        for(auto i:message){
            if(i==' '){ans+=' ';}
            else ans+=mp[i];
        }
        return ans;
    }
};