class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> hash(nums.size() + 1, 0);

        for(int num : nums) {
            hash[num]++;
            if(hash[num] == 2)
                return num;
        }

        return -1;
    }
};