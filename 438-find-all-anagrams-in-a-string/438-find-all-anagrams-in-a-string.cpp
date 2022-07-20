class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
           int ls=s.length();
        int lp=p.length();
        vector<int> ans;
        if(ls<lp) return ans;
        int start=0;
        map<char,int> ms,mp;
        
        for(int i=0; i<lp; i++){
            mp[p[i]]++;
            ms[s[i]]++;
        }
        if(ms == mp) ans.push_back(start);
        for(int i=lp; i<ls; i++){
            if(ms[s[start]]==1){ms.erase(s[start]);}
            else{ms[s[start]]--;}
            start++;
            ms[s[i]]++;
            if(ms == mp) ans.push_back(start);
        }
        return ans;
    }
};