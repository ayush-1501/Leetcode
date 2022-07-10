class Solution {
public:
    void dfs(int i,int j,int init_color,int newcolor,vector<vector<int>>&image)
    {
        int n=image.size();
        int m=image[0].size();
        
        if(i<0 or j<0)return;
        if(i>=n or j>=m)return;
        if(image[i][j]!=init_color)return;
        
        image[i][j]=newcolor;
        
        dfs(i-1,j,init_color,newcolor,image);
        dfs(i+1,j,init_color,newcolor,image);
        dfs(i,j-1,init_color,newcolor,image);
        dfs(i,j+1,init_color,newcolor,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int init_color=image[sr][sc];
           if(image[sr][sc]==newColor)
            return image;  
        dfs(sr,sc,init_color,newColor,image);
        return image;
    }
};