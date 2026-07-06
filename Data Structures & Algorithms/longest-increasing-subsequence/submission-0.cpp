class Solution {
public:
    //dp tc- O(n^2) 1st to tell in interview

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),
        ans=1;
        vector<int> dp(n,1); // stores the length of the LIS till that index

        for(int i =1; i<n; i++) {
            for(int j=0; j<i; j++)  {
                if(nums[j]< nums[i])    {
                    dp[i]= max(dp[i] , dp[j]+1);
                    ans= max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
