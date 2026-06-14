class Solution {
public:

    vector<int> parent;

    int find(int x)    {
        while(parent[x]!=x)  //keep following parents until you reach the root to get the leader
            x=parent[x];

        return x;
    }

    void unionSet(int x, int y)  {
        x=find(x);
        y=find(y);

        parent[y]=x;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        parent.resize(edges.size()+1);

    //initialy all nodes are their own parent
        for(int i=1;i<=edges.size();i++)
            parent[i] = i;

        for(auto & E: edges)    {
            if(find(E[0])==find(E[1]))
                return E;
            else
                unionSet(E[0],E[1]);
        }
        return {-1};
    }
};
