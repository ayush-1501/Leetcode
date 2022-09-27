class Solution {
public:
    string replaceDigits(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                ans+=s[i-1]+s[i]-'0';
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};