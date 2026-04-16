class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int index,vector<int>&nums,int target,vector<int>path)  {
        if(target == 0) {
            ans.push_back(path);
            return;
        }

        if(target < 0) return;

        for(int i=index;i<nums.size();i++)  {
            path.push_back(nums[i]);

            // explore (reuse allowed → i)
            solve(i, nums, target - nums[i], path);

            // backtrack
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        solve(0, nums, target, path);
        return ans;
    }
};
