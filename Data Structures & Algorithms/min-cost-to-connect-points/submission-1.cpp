class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<bool> visited(n,false);
        vector<int>minDist (n, INT_MAX); // to store the min dist to reach each node in the mst

        minDist[0]=0;
        int totalcost=0;

        for(int i=0;i<n;i++)    {
            int node=-1;
            
            for(int j=0;j<n;j++)    {
                if(!visited[j] && ( node == -1 || minDist[j] < minDist[node]) ) // node is unvisited and the dis is lesser or node is not chosed yet
                    node=j;
            }

            visited[node]=true;
            totalcost += minDist[node];

            for(int j=0;j<n;j++)    {
                if(!visited[j]) {
                    int dist= abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]);

                    minDist[j] = min( minDist[j] , dist);
                }
            }
        }
        return totalcost;
    }
};
