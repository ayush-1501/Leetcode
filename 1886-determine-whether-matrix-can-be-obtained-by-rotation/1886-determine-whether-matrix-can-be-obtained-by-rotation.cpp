class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target)return 1;
        int n =mat.size();
        int t=3;
        while (t--){
            for(int i=0; i<mat.size();++i){
                for(int j=0; j<i; ++j){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            reverse(mat.begin(), mat.end());
           
            if(mat==target)return 1;
        }
        return 0;
    }
};
