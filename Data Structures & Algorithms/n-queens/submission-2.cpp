class Solution {
public:

    vector<vector<string>> ans;
    vector<int> diag1,diag2,col1;

    bool isSafe(int col,int row,int n)  {
        if(col1[col]==0 && diag1[row+col]==0 && diag2[row-col+n-1]==0)
            return true;
        return false;
    }

    void solve(int n, vector<string> board,int row)  {
        if(row==n) {
            ans.push_back(board);
            return ;
        }
        for(int col=0;col<n;col++)    {
            if(isSafe(col,row,n)) {
                board[row][col]='Q';
                col1[col]=1;
                diag1[row+col]=1;
                diag2[row-col+n-1]=1;
                solve(n,board,row+1);
                
                // backtrack
                board[row][col] = '.';
                col1[col] = 0;
                diag1[row + col] = 0;
                diag2[row - col + n - 1] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col1.resize(n, 0);
        diag1.resize(2*n - 1, 0);
        diag2.resize(2*n - 1, 0);

        vector<string> board(n,string(n,'.'));
        solve(n,board,0);
        return ans;
    }
};
