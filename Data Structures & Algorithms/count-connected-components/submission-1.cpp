class Solution {
public:

    void dfs(int i,vector<bool> &visited, vector<vector<int>> &graph)    {
        visited[i]=true;

        for(auto nei:graph[i])  
            if(!visited[nei])
                dfs(nei, visited, graph);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        vector<vector<int>> graph(n);
        int components=0;

        for(auto &e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for(int i=0;i<n;i++)   {
            if(!visited[i]) {
                components++;
                dfs(i,visited, graph);
            }
        } 
        return components;   
    }
};
