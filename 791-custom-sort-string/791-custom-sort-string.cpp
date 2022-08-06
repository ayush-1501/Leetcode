class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(auto x:s){mp[x]++;}
        string ans;
        for(int i=0;i<order.size();i++){
            if(mp[order[i]]>0){
                int temp=mp[order[i]];
                while(temp){
                    ans+=order[i];
                    temp--;
                }
                mp[order[i]]=0;
            }
        }
        for(auto x:s){
            if(mp[x]!=0)
                ans+=x;
        }
        return ans;
    }
};