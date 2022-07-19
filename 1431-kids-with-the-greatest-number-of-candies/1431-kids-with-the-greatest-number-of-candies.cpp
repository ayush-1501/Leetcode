class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int m=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=m){
                ans.emplace_back(true);
            }
            else{
                ans.emplace_back(false);
            }
        }
        return ans;
    }
};