class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialize tracking variables with the first element.
        // We track both the max and min because a large negative number 
        // multiplied by another negative number can become the maximum product.
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Store previous values before they get overwritten, 
            // as currMax is used to calculate the new currMin.
            int prevMax = currMax; 
            int prevMin = currMin; 

            // At the current element, the new maximum product could be:
            // 1. The current element itself (starting a new subarray).
            // 2. Current element * prevMin (if both are negative, yielding a positive).
            // 3. Current element * prevMax (extending a positive product chain).
            currMax = max({
                nums[i],
                nums[i] * prevMin,
                nums[i] * prevMax
            });

            // Similarly, track the minimum product for future negative multiplications.
            currMin = min({
                nums[i],
                nums[i] * prevMin,
                nums[i] * prevMax
            });

            // Update the global maximum product found so far.
            ans = max(ans, currMax);
        }
        
        return ans;
    }
};