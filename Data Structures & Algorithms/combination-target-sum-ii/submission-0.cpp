class Solution {
public:

    vector<vector<int>> ans;

    void solve(int index,vector<int>&candidates,int target,vector<int> path)    {
        if(target==0){
            ans.push_back(path);
            return ;
        }
        if (target<0)   return;
        for(int i=index;i<candidates.size();i++)    {
            if(i > index && candidates[i] == candidates[i-1]) continue;

            // pruning
            if(candidates[i] > target) break;
            path.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>path;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,path);
        return ans;
    }
};
