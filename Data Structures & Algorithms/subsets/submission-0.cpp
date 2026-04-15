class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int index,vector<int> &nums,vector<int> path) {
        
        ans.push_back(path);

        for(int i=index;i<nums.size();i++)  {
            path.push_back(nums[i]);

            solve(i+1,nums,path);

            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path; //to store the subset
        solve(0,nums,path);
        return ans;
    }
};
