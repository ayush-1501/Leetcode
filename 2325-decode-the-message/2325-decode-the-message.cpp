class Solution {
public:
    string decodeMessage(string key, string message) {
       stringstream ss(key);
        string s;
        char character='a';
        map<char,char>mp;
        while(ss>>s){
            for(char i:s){
                if(mp.count(i))continue;
                else mp[i]=character++;
            }
        }
        string ans;
        for(char i:message){
            if(i!=' '){
                ans+=mp[i];
            }else{
                ans+=" ";
            }
        }
        return ans;
    }
};