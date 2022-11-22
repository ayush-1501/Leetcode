class Solution {
public:
    void solve(vector<vector<int>>&image,int x,int i,int j,int color,int N,int M){
        if(image[i][j]==color)return;
        
        image[i][j]=color;
        if(j+1<M and x==image[i][j+1])solve(image,x,i,j+1,color,N,M);
        if(j-1>=0 and x==image[i][j-1])solve(image,x,i,j-1,color,N,M);
        if(i+1<N and x==image[i+1][j])solve(image,x,i+1,j,color,N,M);
        if(i-1>=0 and x==image[i-1][j])solve(image,x,i-1,j,color,N,M);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int N=image.size(),M=image[0].size();
        if(image[sr][sc]==color)return image;
        int old_color=image[sr][sc];
        solve(image,old_color,sr,sc,color,N,M);
        return image;
    }
};