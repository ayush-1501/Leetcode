class Solution {

void dfs(int i,int j,vector<vector<int>>&h,vector<vector<int>>&vis,int previous,int N,int M)
{
    
    if((i<0 or j<0 or i>=N or j>=M) or vis[i][j]==1 or h[i][j]<previous )return;   
    
    vis[i][j]=1;
    
     dfs(i+1,j,h,vis,h[i][j],N,M);
     dfs(i-1,j,h,vis,h[i][j],N,M);
     dfs(i,j+1,h,vis,h[i][j],N,M);
     dfs(i,j-1,h,vis,h[i][j],N,M);
}
public:
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
{
    int N=heights.size(),M=heights[0].size();
    vector<vector<int>>ans;
    
    vector<vector<int>>pacific(N,vector<int>(M,0));
    vector<vector<int>>atlantic(N,vector<int>(M,0));
    
    for(int j=0;j<M;++j){
        dfs(0,j,heights,pacific,heights[0][j],N,M);
        dfs(N-1,j,heights,atlantic,heights[N-1][j],N,M);     
    }
    
    for(int i=0;i<N;++i){
        dfs(i,0,heights,pacific,heights[i][0],N,M);
        dfs(i,M-1,heights,atlantic,heights[i][M-1],N,M);     
    }
    
    
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j){
            if(pacific[i][j] && atlantic[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    
    return ans;
 }
};