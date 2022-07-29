class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(string &i:words){
            if(i.length()!=pattern.length())continue;
            vector<char>mark(26,-1);
            bool flag=true;
            map<char,int>m;
            for(int j=0;j<i.size();j++){
                if((mark[i[j]-'a']==-1 and(m.count(pattern[j])==0))or(mark[i[j]-'a']==pattern[j])){
                    m[pattern[j]]++;mark[i[j]-'a']=pattern[j];
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};