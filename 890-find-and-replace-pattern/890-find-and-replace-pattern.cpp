class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(string s : words){
            if(s.size()!=pattern.size())continue;
             vector<char> arr(26,-1);
             unordered_map<char,int>m;
             bool flag = true;
             for(int j = 0;j<s.size();j++){
                char a=s[j];
                char b=pattern[j];
                if((arr[a-'a']==-1 && m.count(b)==0)||arr[a-'a']== b) {
                    arr[a-'a'] = b;
                    m[b] = 1;
                }
                else{
                   flag = false;
                    break;
                } 
             }
            if(flag){
                ans.emplace_back(s);
            }
            
        }
        return ans;
    }
};