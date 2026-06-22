class Solution {
        public:

            void dfs(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &visited, int prevHeight) {

                    int m=heights.size(), n=heights[0].size();
                            if(r<0 || r>=m || c<0 || c>=n || visited[r][c] || heights[r][c] < prevHeight)
                                        return;
                                                
                                                        visited[r][c]=true;

                                                                dfs(r-1,c,heights,visited,heights[r][c]);
                                                                        dfs(r+1,c,heights,visited,heights[r][c]);
                                                                                dfs(r,c-1,heights,visited,heights[r][c]);
                                                                                        dfs(r,c+1,heights,visited,heights[r][c]);
                                                                                            }

                                                                                                vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
                                                                                                        int m=heights.size(), n=heights[0].size();

                                                                                                                vector<vector<bool>> pacific(m,vector<bool>(n,false));
                                                                                                                        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

                                                                                                                                for(int r=0;r<m;r++)    {
                                                                                                                                            dfs(r,0,heights, pacific, heights[r][0]);
                                                                                                                                                        dfs(r,n-1,heights, atlantic, heights[r][n-1]);
                                                                                                                                                                }
                                                                                                                                                                        for(int c=0;c<n;c++)    {
                                                                                                                                                                                    dfs(0,c,heights, pacific, heights[0][c]);
                                                                                                                                                                                                dfs(m-1,c,heights, atlantic, heights[m-1][c]);
                                                                                                                                                                                                        }

                                                                                                                                                                                                                vector<vector<int>> ans;
                                                                                                                                                                                                                        for(int r=0;r<m;r++)    
                                                                                                                                                                                                                                    for(int c=0;c<n;c++)    
                                                                                                                                                                                                                                                    if(atlantic[r][c] && pacific[r][c])
                                                                                                                                                                                                                                                                        ans.push_back({r,c});
                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                        return ans;
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                            };