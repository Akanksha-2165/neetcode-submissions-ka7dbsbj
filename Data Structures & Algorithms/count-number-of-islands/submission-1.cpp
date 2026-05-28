class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &grid)  {
        int m=grid.size(),n=grid[0].size();
        if( r<0 ||r>=m || c<0 ||c>=n || grid[r][c]=='0')
            return;
        grid[r][c]='0';
        dfs(r-1,c,grid);
        dfs(r+1,c,grid);
        dfs(r,c-1,grid);
        dfs(r,c+1,grid);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)    
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1') {
                    islands++;
                    dfs(i,j,grid);
                }
        return islands;
    }
};
