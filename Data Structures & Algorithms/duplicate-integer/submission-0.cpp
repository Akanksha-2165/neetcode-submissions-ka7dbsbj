class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> seen;
        for(int i=0; i<nums.size(); i++)    {
            if(seen.find(nums[i]) != seen.end())
                return true;
            seen.insert(nums[i]);
        }
        return false;
    }
};

/*
INTUITION:
- We only need to know whether we've seen an element before.
- Use an unordered_set to store previously seen elements.
- For each number:
    - If it's already in the set, return true.
    - Otherwise, insert it.
- If the loop finishes, there are no duplicates.

Time Complexity : O(n) average
Space Complexity: O(n)
*/