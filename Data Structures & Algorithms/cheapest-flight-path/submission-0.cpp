class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &f : flights)  
            graph[f[0]].push_back({f[1],f[2]});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            
            greater<tuple<int,int,int>>
        > pq;
        pq.push({0,src,0});

        while(!pq.empty())  {
            auto[cost, node, edges] = pq.top();
            pq.pop();
            if (cost > dist[node][edges])
                continue;
            if (node == dst)
                return cost;
            if (edges == k + 1)
                continue;
            for (auto &[nei, price] : graph[node]) {
                int newCost = cost + price;
                int newEdges = edges + 1;
                if(newCost < dist[nei][newEdges])   {
                    dist[nei][newEdges] = newCost;
                    pq.push({newCost, nei, newEdges});
                }
            }
        }
        return -1;
    }
};
