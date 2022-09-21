class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[i]=nums[i];
            if(nums[i]%2==0){
                sum+=nums[i];
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int t=queries[i][1];
            int l=mp[t];
            if(mp[t]%2==0){
               // sum-=mp[t];
                if((queries[i][0]+mp[t])%2==0){
                    sum+=queries[i][0];
                }
                else{
                    sum-=mp[t];
                }
                mp[t]+=queries[i][0];
            }
            else{
                if((queries[i][0]+l)%2==0){
                    sum+=queries[i][0]+l;
                }
             mp[t]+=queries[i][0];
            }
            ans.emplace_back(sum);
        }
        return ans;
    }
};