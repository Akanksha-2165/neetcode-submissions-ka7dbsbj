class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int>&nums,int index,vector<int> path)  {
        ans.push_back(path);

        for(int i=index;i<nums.size();i++)  {
            if(i>index && nums[i]==nums[i-1])  continue;

            path.push_back(nums[i]);
            solve(nums,i+1,path);
            
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        solve(nums,0,path);
        return ans;
    }
};
