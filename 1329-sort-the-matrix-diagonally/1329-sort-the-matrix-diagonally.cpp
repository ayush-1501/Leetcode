class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         vector<int> k;
        int m = mat.size() , n = mat[0].size();
        for (int r=0;r<m;r++) {
            k.clear();
            for (int j=0,i=r; j<n && i<m ; j++,i++) k.emplace_back(mat[i][j]);    
            sort(k.begin(),k.end());
            for (int j=0,i=r; j<n && i<m ; j++,i++) mat[i][j]=k[j];            
        }
        for (int c=1; c<n; c++){
            k.clear();
            for (int i=0,j=c;j<n && i<m;i++,j++) k.emplace_back(mat[i][j]);   
            sort(k.begin(),k.end());
            for (int i=0, j=c; j<n && i<m; i++, j++) mat[i][j] = k[i];        
        }
        return mat;
    }
};