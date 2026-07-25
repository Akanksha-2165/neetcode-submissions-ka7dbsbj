class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,1);

        for(int i=1;i<n;i++)  
            result[i]= result[i-1]* nums[i-1];

        int right_prod=1;

        for(int i= n-1; i>=0;i--)   {
            result[i]= result[i] * right_prod;
            right_prod *= nums[i];
        }
        return result;

    }
};
// Brute Force: For each element, multiply all other elements using a nested loop.
// Time Complexity: O(n²) - double loop over array
// Space Complexity: O(1) - extra space (excluding O(n) output array)

// Optimal: Two-pass prefix/suffix product (combines left & right products on the fly).
// Time Complexity: O(n) - two linear passes
// Space Complexity: O(1) - extra space (excluding O(n) output array)