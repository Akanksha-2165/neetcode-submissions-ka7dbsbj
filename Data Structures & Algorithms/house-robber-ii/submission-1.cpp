class Solution {
public:

    int robLinear(vector<int> &nums, int start, int end)    {
        int next1=0;
        int next2=0;

        for(int i=end; i>=start; i--)   {
            int take= nums[i]+ next2;
            int skip= next1;
            int curr= max(take, skip);

            next2=next1;
            next1=curr;
        }
        return next1;
    }

    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n == 1)  return nums[0];

        return max(robLinear(nums,0,n-2), (robLinear(nums,1,n-1)));
    }
};
