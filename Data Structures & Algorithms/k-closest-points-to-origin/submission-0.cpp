class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> minheap;
        vector<vector<int>> res;
        for(auto &p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            minheap.push({dist, p});
        }
        while(k--)  {
            res.push_back(minheap.top().second);
            minheap.pop(); 
        }
        return res;
    }
};
