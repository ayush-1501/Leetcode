class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums) m[i]++;
        int ans=0;
        int count=1;
        for(auto i=m.begin();i!=m.end();++i){
            while(m.find(i->first+1)!=m.end()){ count++;++i;}
            ans=max(ans,count);
            count=1;
        }
        return ans;
    }
};