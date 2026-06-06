class Solution {
public:

    bool dfs(int course, vector<vector<int>> &graph, vector<int> &state) {
        if(state[course]==1)    return false;
        if(state[course]==2)    return true;

        state[course]=1;
        
        for(auto pre: graph[course])
            if(!dfs(pre,graph,state))
                return false;
        
        state[course]=2;
        return true;
        
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); // to store the prerequsite of courses
        vector<int> state(numCourses, 0); // to store 0- unvisited 1-visiting 2- visited

        for(auto &p: prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        for(int i=0;i<numCourses;i++)   
            if(!dfs(i,graph, state))
                return false;
        
        return true;
    }
};
