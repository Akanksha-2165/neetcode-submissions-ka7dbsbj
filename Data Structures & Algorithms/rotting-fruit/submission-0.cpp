class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int freshfruits=0, minutes=0;
        queue<pair<int,int>> rotten;

        for(int i=0;i<m;i++)        
            for(int j=0;j<n;j++)    {
                if(grid[i][j]==2)
                    rotten.push({i,j});
                else if(grid[i][j]==1)
                    freshfruits++;
            }

        int directions[4][2]={{1,0}, {-1,0} , {0,1} ,{0,-1}};
        
        while(!rotten.empty())   {
            bool rot=false;

            int size= rotten.size();
            for(int i=0;i<size;i++) {
                auto [r,c] =rotten.front();
                rotten.pop();
                for(auto &dir: directions)  {
                    int nr= r + dir [0];
                    int nc= c + dir[1];
                    if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]==0 || grid[nr][nc]==2)
                        continue;

                    grid[nr][nc] = 2;
                    rotten.push({nr,nc});
                    freshfruits--;
                    rot=true;
                }
            }
            if(rot)
                minutes++;
        }
        if(freshfruits>0)   return -1;
        return minutes;
    }
};
