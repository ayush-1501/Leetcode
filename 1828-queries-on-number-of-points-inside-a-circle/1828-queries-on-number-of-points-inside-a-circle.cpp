class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
       vector<int>ans;
        for(auto i:queries){
            int count=0;
            for(auto j:points){
                if(pow((i[0]-j[0]),2)+pow((i[1]-j[1]),2)<=pow(i[2],2)){
                    count++;
                }
            }
            ans.emplace_back(count);
        }
        return ans;
    }
};