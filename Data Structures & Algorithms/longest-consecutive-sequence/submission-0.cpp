class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st){

            // Is this the start of a sequence?
            if(st.count(num - 1))
                continue;

            int length = 1;
            int curr = num;

            while(st.count(curr + 1)){
                curr++;
                length++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};