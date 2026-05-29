class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // push all treasure cells
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 0)
                    q.push({r,c});
            }
        }

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            for(auto [dr,dc] : dir) {

                int nr = r + dr;
                int nc = c + dc;

                // valid INF cell
                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   grid[nr][nc] == 2147483647) {

                    grid[nr][nc] = grid[r][c] + 1;

                    q.push({nr,nc});
                }
            }
        }
    }
};
 