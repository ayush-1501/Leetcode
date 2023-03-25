class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
              for (int i=0; i<9; i++){
            if (!is_valid_row(board, i))
                return false;
            if (!is_valid_column(board, i))
                return false;
        }
        
        for (int i=0; i<9; i+=3)
            for (int j=0; j<9; j+=3)
                if (!is_valid_box(board, i, j))
                    return false;
        return true;
    }

    bool is_valid_row(vector<vector<char> >& board, int row){
        unordered_set<char> used;
        for (int j=0; j<9; j++){
            if (board[row][j] != '.'){
                if (used.find(board[row][j])!=used.end())
                    return false;
                used.insert(board[row][j]);
            }
        }
        return true;
    }
    
    bool is_valid_column(vector<vector<char> >& board, int col){
        unordered_set<char> used;
        for (int i=0; i<9; i++)
        {
            if (board[i][col]!='.')
            {
                if (used.find(board[i][col])!=used.end())
                    return false;
                used.insert(board[i][col]);
            }
        }
        return true;
    }
    bool is_valid_box(vector<vector<char> >& board, int row, int col)
    {
        unordered_set<char> used;
        for (int i=row; i<row+3; i++)
            for (int j=col; j<col+3; j++)
                if (board[i][j]!='.')
                {
                    if (used.find(board[i][j])!=used.end())
                        return false;
                    used.insert(board[i][j]);
                }
        return true;  
    }
};