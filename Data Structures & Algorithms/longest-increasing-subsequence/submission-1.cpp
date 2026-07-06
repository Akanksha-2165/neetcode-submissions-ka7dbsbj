class Solution {
public:
/*
    //dp tc- O(n^2) 1st to tell in interview

    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;

        int n=nums.size(),
        ans=1;
        vector<int> dp(n,1); // dp[i] = length of the LIS ending at index i

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
*/
    // optimal sol next in interview tc- O(n log n)
    // tails algorithm, using binary search 

    int lengthOfLIS(vector<int>& nums)  {
        int n= nums.size();
        vector<int> tails; // to store the last minimun element of each length if LIS

        for(int x: nums)    {
            if(tails.empty() || tails.back() < x)
                tails.push_back(x);
            else {
                auto it= lower_bound( 
                    tails.begin(),
                    tails.end(),
                    x
                );
                *it =x;
            }
        }
        return tails.size();
    }
};
