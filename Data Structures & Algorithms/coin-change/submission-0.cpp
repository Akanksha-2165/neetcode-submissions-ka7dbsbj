class Solution {
public:

    int solve(int rem, vector<int> &dp, vector<int> &coins)    {
        int mini=INT_MAX;

        if(rem==0)
            return 0;
        
        if(rem<0)
            return INT_MAX;

        if(dp[rem]!= -1)
            return dp[rem];

        for(int c :coins)   {
            int ans= solve(rem-c, dp, coins);

            if(ans != INT_MAX)  
                mini= min(mini, ans+1);
        }
        return dp[rem]=mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);  // stores the minimum number of coins to make every amount from 0 to amt
        int ans= solve(amount, dp, coins);
        return (ans== INT_MAX) ? -1 : ans;
    }
};
