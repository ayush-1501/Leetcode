class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int c=0;
        map<string,bool>m;
    
        for(auto i:words){
            if(m.find(i)!=m.end()){if(m[i]==true){++c;}continue;}
            
           int j=0;
           for(int k=0;k<s.size() && j<i.size();++k){
              if(s[k]==i[j]){++j;}
            }
    
            if(j==i.size()){m[i]=true;}
            else{m[i]=false;}
            
            if(m[i]==true){++c;}
            
        }
        return c;
    }
};