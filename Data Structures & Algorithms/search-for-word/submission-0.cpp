class Solution {
public:

    bool ans;

    bool solve(vector<vector<char>>& board,string word,int i,int j,int k)   {
        if(k==word.size())  return true;

        int rows = board.size();
        int cols = board[0].size();

        
        if(i < 0 || j < 0 || i >= rows || j >= cols ||board[i][j] != word[k])    
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        
        bool found = 
            solve(board, word, i-1, j, k+1) ||
            solve(board, word, i+1, j, k+1) ||
            solve(board, word, i, j-1, k+1) ||
            solve(board, word, i, j+1, k+1);

        board[i][j] = temp;
         return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
