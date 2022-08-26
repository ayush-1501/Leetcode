class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<string,int>mp;
        for(int i=0;i<31;i++){
            string a=to_string((int)pow(2,i));
            sort(a.begin(),a.end());
            mp[a]++;
        }
        string t=to_string(n);
        sort(t.begin(),t.end());
        return mp.find(t)!=mp.end();
    }
};