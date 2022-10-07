class Solution {
public:
    set<string>ans;
    void solve(string &s,string add,int idx){
        if(idx==s.size()){
           if(add.size()==s.size()) ans.insert(add);
            return;
        }
        
        if(isdigit(s[idx]))solve(s,add,idx+1);
        
        add+=toupper(s[idx]);
        solve(s,add,idx+1);
        add.pop_back();
        
        add+=tolower(s[idx]);
        solve(s,add,idx+1);
        add.pop_back();
        
        return;
    }
    vector<string> letterCasePermutation(string s) {
        string add;
        int idx=0;
        solve(s,add,idx);
        vector<string>ans1;
        for(auto i:ans){
            ans1.emplace_back(i);
        }
        return ans1;
    }
};