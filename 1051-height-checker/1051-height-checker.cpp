class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>newh=heights;
        sort(newh.begin(),newh.end());
        int count=0;
        for(int i=0;i<newh.size();i++){
            if(heights[i]!=newh[i]){count++;}
        }
        return count;
    }
};