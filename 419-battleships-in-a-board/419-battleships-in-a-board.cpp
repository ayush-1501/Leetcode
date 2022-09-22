class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>&board){
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]=='.'){return;}
        
        board[i][j]='.';
        dfs(i+1,j,n,m,board);
        dfs(i,j+1,n,m,board);
        dfs(i,j-1,n,m,board);
        dfs(i-1,j,n,m,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(i,j,n,m,board);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};