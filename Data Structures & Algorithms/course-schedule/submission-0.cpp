class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return false; // cycle
        if (state[node] == 2) return true;  // already processed

        state[node] = 1; // visiting

        for (int nei : adj[node]) {
            if (!dfs(nei, adj, state))
                return false;
        }

        state[node] = 2; // visited
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj, state))
                return false;
        }

        return true;
    }
};