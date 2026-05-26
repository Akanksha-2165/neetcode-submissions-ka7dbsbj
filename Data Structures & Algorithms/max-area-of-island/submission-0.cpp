class Solution {
public:

    int dfs(int r,int c,int m,int n , vector<vector<int>> &grid)   {
        if(r<0 || r>=m || c<0 ||c>=n || grid[r][c]==0)
            return 0;

        grid[r][c]=0;
        return 1
            + dfs(r-1,c,m,n,grid)
            + dfs(r+1,c,m,n,grid)
            + dfs(r,c-1,m,n,grid)
            + dfs(r,c+1,m,n,grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int isisland=0;int maxi=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)    {
            for(int j=0;j<n;j++)    {
                if(grid[i][j]==1){
                    int area=dfs(i,j,m,n,grid);
                    maxi=max(maxi,area);
                }
            }
        }
        return maxi;
    }
};
