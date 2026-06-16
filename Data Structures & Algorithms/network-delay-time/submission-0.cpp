class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n+1); // adjacency list to store neighnor node and dist from it , need vector<vector<pair cause 1 node can have many adj nodes
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater <pair<int,int>>> pq;// min heap stores- dist,node to get the mini dist at that step
        vector<int> dist( n+1,INT_MAX); // to store the min dist possible 

        dist[k]=0; //start node
        pq.push({0,k}); //start

        for(auto &edge: times)  {
            int u= edge[0];
            int v= edge[1];
            int w= edge[2];

            graph[u].push_back({v,w});
        }
        while(!pq.empty())  {
            auto [d,node]= pq.top();// getting dist and node 
            pq.pop();
            if(d>dist[node]) // skip bigger dist no need to process it 
                continue;

            for( auto &[nei, wt]: graph[node])  {
                if(d+wt < dist[nei])    {
                    dist[nei]=d+wt;
                    pq.push({d+wt, nei});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++)   
            maxi=max(dist[i],maxi);
        
        return maxi==INT_MAX ? -1 : maxi;
    }
};
