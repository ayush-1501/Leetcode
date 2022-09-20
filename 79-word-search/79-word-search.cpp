class Solution {
public:
    bool recur(vector<vector<char>>& board,string &word,int i,int dx,int dy,int N,int M){
        if(dx<0 or dy<0 or dx>=N or dy>=M)return false;
        if(i==word.size())return true;
        if(i>word.size()){return false;}
        if(board[dx][dy]!=word[i])return false;
        board[dx][dy]='$';
    
        bool ans=recur(board,word,i+1,dx,dy+1,N,M)or 
                 recur(board,word,i+1,dx,dy-1,N,M)or
                 recur(board,word,i+1,dx-1,dy,N,M)or 
                 recur(board,word,i+1,dx+1,dy,N,M);
        
        
        board[dx][dy]=word[i];
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==1 and board[0].size()==1 and word.size()==1){
            if(board[0][0]==word[0]){
                return true;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                 if(recur(board,word,0,i,j,board.size(),board[0].size())){
                     return true;
                 }
            }
        }
        return false;
    }
};