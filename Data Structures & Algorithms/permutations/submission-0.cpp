class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int>&nums,vector<int>path,vector<bool> visited)    {
        if(path.size()==nums.size())    {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++)  {
            if(visited[i]==true)    continue;

            visited[i]=true;
            path.push_back(nums[i]);
            solve(nums,path,visited);

            path.pop_back();
            visited[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> visited(nums.size(),false);
        solve(nums,path,visited);
        return ans;    
    }
};
