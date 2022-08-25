class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         map<char,int>m1,m2;
        for(auto i:ransomNote){
            m1[i]++;
        }
        for(auto i:magazine){
            m2[i]++;
        }
        for(auto i:m1){
            if(m2.count(i.first) and m2[i.first]>=i.second){
               continue;
            }else{
               return false;
            }
        }
        return true;
    }
};