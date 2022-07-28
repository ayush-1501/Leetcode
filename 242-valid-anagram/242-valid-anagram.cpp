class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m,l;
        for(char &i:s){
            m[i]++;
        }
        for(auto &i:t){
            if(!m.count(i)){return false;}
            if(m[i]>1){m[i]--;}
            else m.erase(i);
        }
      return m.size()==0;
    }
};