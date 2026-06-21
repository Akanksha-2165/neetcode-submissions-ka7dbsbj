class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size(), false);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // to store [cost,node] to get the dis to the node 
        int totalcost=0;

        pq.push({0,0}); //init stores dis 0 to node 0
        int edgesUsed = 0;

        while(edgesUsed<points.size())  {
            auto[cost,node]=pq.top();
            pq.pop();
            if(visited[node])
                continue;

            visited[node]=true;
            edgesUsed++;
            totalcost+=cost;

            for(int i=0;i<points.size();i++)    {
                if(!visited[i]) {
                    int x1 =points[node][0];
                    int y1 =points[node][1];
                    int x2= points[i][0];
                    int y2= points[i][1];
                    pq.push( {abs(x1-x2)+ abs(y1-y2) ,i } );
                }
            }
        }
        return totalcost;
    }
};
