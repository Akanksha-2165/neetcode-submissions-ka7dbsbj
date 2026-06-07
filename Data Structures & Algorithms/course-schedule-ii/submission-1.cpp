class Solution {
public:

    bool dfs(int course, vector<vector<int>> &graph, vector<int> &state, vector<int> &ans)    {
        if(state[course] == 1)  return false;
        if(state[course] == 2)  return true;

        state[course]=1;

        for(auto pre: graph[course])    
            if(!dfs(pre,graph, state, ans))
                return false;

        state[course]=2;
        ans.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> state(numCourses,0);
        vector<int> ans;

        for(auto &p: prerequisites)
            graph[p[0]].push_back(p[1]);

        for(int i=0;i<numCourses; i++)
            if(!dfs(i,graph,state,ans))
                return {};
        
        return ans;
    }
};
