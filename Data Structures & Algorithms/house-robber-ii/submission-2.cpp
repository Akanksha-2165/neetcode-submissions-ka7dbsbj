class Solution {
public:

    // Helper function to solve the original House Robber I problem
    // on a linear range of houses from index 'start' to 'end'.
    int robLinear(vector<int> &nums, int start, int end) {

        // next1 stores the maximum profit from house i+1 onward.
        int next1 = 0;

        // next2 stores the maximum profit from house i+2 onward.
        int next2 = 0;

        // Traverse from right to left because our recurrence depends on
        // dp[i+1] and dp[i+2].
        for (int i = end; i >= start; i--) {

            // Option 1: Rob the current house.
            // Since adjacent houses cannot be robbed,
            // jump to i+2.
            int take = nums[i] + next2;

            // Option 2: Skip the current house.
            int skip = next1;

            // Store the better of the two choices.
            int curr = max(take, skip);

            // Shift the DP window:
            // next2 becomes old next1 (dp[i+1])
            // next1 becomes current answer (dp[i])
            next2 = next1;
            next1 = curr;
        }

        // Maximum money that can be robbed starting from 'start'.
        return next1;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge case:
        // If there is only one house, rob it.
        if (n == 1)
            return nums[0];

        // Since houses are arranged in a circle,
        // the first and last house are adjacent.
        //
        // Therefore, we cannot rob both.
        //
        // We split the problem into two independent cases:
        //
        // Case 1: Rob from house 0 to n-2 (exclude last house).
        // Case 2: Rob from house 1 to n-1 (exclude first house).
        //
        // Each case becomes the original House Robber I problem.
        return max(
            robLinear(nums, 0, n - 2), // Exclude last house
            robLinear(nums, 1, n - 1)  // Exclude first house
        );
    }
};