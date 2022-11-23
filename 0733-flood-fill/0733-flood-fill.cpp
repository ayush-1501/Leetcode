class Solution {
public:
    void solve(vector<vector<int>>&image,int i,int j,int color,int x){
        if(i>=image.size() or i<0 or i>=image[0].size() or j<0)return ;
        if(image[i][j]!=x or image[i][j]==color)return;
        image[i][j]=color;
        solve(image,i+1,j,color,x);
        solve(image,i,j+1,color,x);
        solve(image,i-1,j,color,x);
        solve(image,i,j-1,color,x);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color=image[sr][sc];
        if(old_color==color)return image;
        solve(image,sr,sc,color,old_color);
        return image;
    }
};