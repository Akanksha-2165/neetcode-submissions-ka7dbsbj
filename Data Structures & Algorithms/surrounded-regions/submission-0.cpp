class Solution {
public:

    void dfs(int r, int c, vector<vector<char>> &board)  {
        int m=board.size(), n=board[0].size();

        if(r<0 || r>=m || c<0 || c>=n || board[r][c]!='O')
            return;

        board[r][c]='S';

        dfs(r-1,c,board); 
        dfs(r+1,c,board); 
        dfs(r,c-1,board); 
        dfs(r,c+1,board); 
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();

        for(int c=0;c<n;c++)    {
            dfs(0,c,board);
            dfs(m-1,c,board);
        }
        for(int r=0;r<m;r++)    {
            dfs(r,0,board);
            dfs(r,n-1,board);
        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)    {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='S')
                    board[i][j]='O';
            }
    }
};
