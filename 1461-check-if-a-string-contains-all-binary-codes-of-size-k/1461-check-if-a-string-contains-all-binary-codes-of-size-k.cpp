class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()){return false;}
        long long p=pow(2,k);
        unordered_set<string>store;
        for(int i{0};i<s.size()-k+1;i++){
           // cout<<s.substr(i,k)<<" ";
            store.insert(s.substr(i,k));
        }
    
       // cout<<s.size();
        if(store.size()==p){return true;}
        return false;
    }
};