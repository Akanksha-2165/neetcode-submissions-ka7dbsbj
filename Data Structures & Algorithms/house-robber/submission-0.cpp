class Solution {
public:
    // Recursive function that returns the maximum money
    // we can rob starting from house 'i'
    int solve(int i, vector<int>& nums, vector<int>& dp) {

        // Base case:
        // If we've gone past the last house,
        // there is no money left to rob.
        if (i >= nums.size())
            return 0;

        // If we've already solved this subproblem,
        // return the stored answer.
        if (dp[i] != -1)
            return dp[i];

        // Option 1: Rob the current house.
        // Then we must skip the next house.
        int take = nums[i] + solve(i + 2, nums, dp);

        // Option 2: Skip the current house.
        int skip = solve(i + 1, nums, dp);

        // Store and return the better of the two choices.
        dp[i] = max(take, skip);

        return dp[i];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // dp[i] stores the maximum money we can rob
        // starting from house i.
        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};