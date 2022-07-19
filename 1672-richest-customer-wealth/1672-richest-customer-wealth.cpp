class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_sum=0;
        for(auto i:accounts){
            int sum=0;
            for(int j:i){
                sum+=j;
            }
            max_sum=max(sum,max_sum);
        }
        return max_sum;
    }
};