class Solution {
public:
    // Recursive function to find the minimum cost to reach the top
    // starting from index i
    int solve(int i, vector<int> &cost, vector<int> &dp) {

        // Base case:
        // If we've reached or crossed the top, no more cost is needed
        if (i >= cost.size())
            return 0;

        // If we've already solved this subproblem,
        // return the stored answer
        if (dp[i] != -1)
            return dp[i];

        // Pay the cost of the current step,
        // then choose the cheaper of taking 1 or 2 steps
        dp[i] = cost[i] + min(
            solve(i + 1, cost, dp),
            solve(i + 2, cost, dp)
        );

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // dp[i] = minimum cost to reach the top starting from step i
        vector<int> dp(n, -1);

        // We can start from either step 0 or step 1
        return min(
            solve(0, cost, dp),
            solve(1, cost, dp)
        );
    }
};