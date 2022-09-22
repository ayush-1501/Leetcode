class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans,t;
        while(ss>>t){
            reverse(t.begin(),t.end());
            ans+=t+" ";
        }
        ans.pop_back();
        return ans;

    }
};