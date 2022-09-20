class Solution {
public:
    int countPairs(vector<int>&nums) {
         int n=nums.size();
         long long ans=0;
         unordered_map<int,int> m;
          for(auto &i:nums){
           for(int j=0;j<31;++j){
               int cal=1<<j;
            if(m.find(cal-i)!=m.end()){
                ans=ans +m[cal-i];
             }
           } 
          m[i]++;
        }
     return (int)(ans%1000000007);
    }
};