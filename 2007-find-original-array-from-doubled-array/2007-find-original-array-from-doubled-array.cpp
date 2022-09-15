class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>mp;
        if(changed.size()%2!=0){return {};}
        for(int i:changed){
            mp[i]++;
        }
        sort(changed.begin(),changed.end());
        vector<int>ans;
        for(int i=0;i<changed.size();i++){
            if(changed[i]==0){
                if(mp[changed[i]]>1){
                    ans.emplace_back(changed[i]);
                    mp[changed[i]]-=2;
                }
                continue;
            }
           if(mp[changed[i]]>=1 and mp[changed[i]*2]>=1){
               ans.emplace_back(changed[i]);
               mp[changed[i]]--;
               mp[changed[i]*2]--;
           }
        }
        if(ans.size()==changed.size()/2){
            return ans;
        }
        return {};
    }
};