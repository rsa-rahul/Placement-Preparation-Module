class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        if(board.empty())return;
        solve(board);
    }
       private:
    bool solve(vector<vector<char>>& board)
    {   
        for(int i =0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char x = '1' ; x <= '9'; x++)
                    {
                       if(isValid(board, i, j, x))
                        {   board[i][j] = x;
                            if(solve(board))return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
     return true;
    }    
    bool isValid(vector<vector<char>>& board, int x, int y, char val)
    {
        for(int c = 0; c < board.size(); c++)
        {
            if(board[x][c] != '.' && board[x][c] == val)return false;
        }
        
         for(int c = 0; c < board[0].size(); c++)
        {
            if(board[c][y] != '.' && board[c][y] == val)return false;
        }
        
        int smx = 3 * (x/3);
        int smy = 3 * (y/3);
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[smx + i][smy + j] != '.' && board[smx + i][smy + j] == val)return false;
            }
        }
        
        return true;
        
    }
};