class Solution {
    public:
        int swimInWater(vector<vector<int>>& grid) {
                int n = grid.size(); //square mat
                        vector<vector<int>> dist (n,vector<int>(n,INT_MAX));
                                priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

                                        int directions[4][2] = {
                                                    {-1,0},
                                                                {1,0},
                                                                            {0,-1},
                                                                                        {0,1}
                                                                                                };

                                                                                                        dist[0][0]= grid[0][0];
                                                                                                                pq.push( {dist[0][0],0,0} ); //init

                                                                                                                        while(!pq.empty())  {
                                                                                                                                    auto curr= pq.top();
                                                                                                                                                pq.pop();

                                                                                                                                                            int time= curr[0];
                                                                                                                                                                        int r= curr[1];
                                                                                                                                                                                    int c= curr[2];
                                                                                                                                                                                                if(r == n-1 && c == n-1)
                                                                                                                                                                                                                return time;

                                                                                                                                                                                                                            if(time > dist[r][c])
                                                                                                                                                                                                                                            continue;

                                                                                                                                                                                                                                                        for(auto &dir: directions)  {
                                                                                                                                                                                                                                                                        int nr= r+ dir[0];
                                                                                                                                                                                                                                                                                        int nc= c+ dir[1];
                                                                                                                                                                                                                                                                                                        if(nr<0 || nr >=n || nc<0 || nc >=n)   
                                                                                                                                                                                                                                                                                                                            continue;
                                                                                                                                                                                                                                                                                                                                            int newtime= max(time, grid[nr][nc]);
                                                                                                                                                                                                                                                                                                                                                            if(newtime < dist[nr][nc])  {
                                                                                                                                                                                                                                                                                                                                                                                dist[nr][nc]=newtime;
                                                                                                                                                                                                                                                                                                                                                                                                    pq.push( {newtime, nr,nc} );
                                                                                                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                return -1;
                                                                                                                                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                    };
