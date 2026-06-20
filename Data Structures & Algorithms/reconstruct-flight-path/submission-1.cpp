// in this question we have to explore each edge which in graph theory is eulerian path the alogrithm we use for 
// this is Hierholzer's Algorithm an then we adapt it to return the lexicographical order

class Solution {
public:

    unordered_map <string, priority_queue<string, vector<string>, greater<string>>> graph; // to map each airport to possible airports
    vector<string> ans;

    void dfs(string airport)    {
        while(!graph[airport].empty())  {

            string next= graph[airport].top();
            graph[airport].pop();

            dfs(next);
        }
        ans.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto &t : tickets)  {
            graph[t[0]] . push(t[1]); // string not a pair so can't use first/second and a priority q need push func
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end()); // reverse returns void
        return ans;
    }
};
