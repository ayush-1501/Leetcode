class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int ans=0;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                ans+=min(need[i],need[i+1]);
                need[i+1] = max(need[i],need[i+1]);
            }
        }
        return ans;
    }
};