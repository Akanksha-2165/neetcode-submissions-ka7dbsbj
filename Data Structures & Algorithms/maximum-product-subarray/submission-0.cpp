class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax= nums[0],
        currMin= nums[0],
        ans= nums[0];

        for(int i=1; i< nums.size() ;i++)   {
            int prevMax= currMax; 
            int prevMin= currMin; 

            currMax= max({
                nums[i],
                nums[i]* prevMin,
                nums[i]* prevMax
            });
            currMin= min({
                nums[i],
                nums[i]* prevMin,
                nums[i]* prevMax
            });

            ans= max(ans, currMax);
        }
        return ans;
    }
};
