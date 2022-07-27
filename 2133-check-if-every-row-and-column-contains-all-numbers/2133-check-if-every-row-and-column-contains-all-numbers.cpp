class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        set<int>s,temp;
      
        for(int i=0;i<n;i++){
            s.clear();temp.clear();
            for(int j=0;j<n;j++){
                s.insert(matrix[i][j]);
                temp.insert(matrix[j][i]);
            }
            if(s.size()!=n or temp.size()!=n){return false;}
        }
        return true;
    }
};