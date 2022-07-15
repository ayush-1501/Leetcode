class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        for(int i=0;i<s.size();i++){
            if(m.count(s[i]) and m.find(s[i])->second==1){
                return i;
            }
        }
        return -1;
    }
};