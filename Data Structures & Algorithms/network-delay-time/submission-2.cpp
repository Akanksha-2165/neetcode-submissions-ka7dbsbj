class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                vector<vector<pair<int,int>>> graph(n+1); // to store adj list at node 1 we store node to reach and the weight 
                        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;// to store the node currently processing
                                vector<int> dist(n+1, INT_MAX);// to store min dist to each node

                                        pq.push({0,k}); // start node
                                                dist[k]=0;

                                                        for(auto &edge: times)  {
                                                                    int u=edge[0];
                                                                                int v=edge[1];
                                                                                            int w=edge[2];

                                                                                                        graph[u].push_back({v,w});
                                                                                                                }   
                                                                                                                        while(!pq.empty())  {
                                                                                                                                    auto [d, node]= pq.top();
                                                                                                                                                pq.pop();

                                                                                                                                                            if(d>dist[node])
                                                                                                                                                                            continue;

                                                                                                                                                                                        for(auto &[nei,wt]: graph[node])  { // checking all the neig from curr node
                                                                                                                                                                                                        if(d+wt < dist[nei]){
                                                                                                                                                                                                                            dist[nei]=d+wt;
                                                                                                                                                                                                                                                pq.push({d+wt,nei});
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                            int maxi=INT_MIN;
                                                                                                                                                                                                                                                                                                    for(int i=1;i<=n;i++)   
                                                                                                                                                                                                                                                                                                                maxi=(max(maxi,dist[i]));

                                                                                                                                                                                                                                                                                                                        return maxi==INT_MAX ? -1 : maxi;
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                            };
