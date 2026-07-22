class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        vector<int> ans(26, 0);

        for(int i=0; i<s.size(); i++)   {
            ans[s[i]-'a']++;   
            ans[t[i]-'a']--;
        }

        return ans == vector<int> (26,0);
    }
};
/*
INTUITION:
- Two strings are anagrams if they contain the same characters with the same frequencies.
- If their lengths differ, they can never be anagrams.
- Use a frequency array of size 26 (lowercase English letters).
- Increment the count for each character in s and decrement for each character in t.
- If all frequencies become 0, both strings have identical character counts.

BRUTE FORCE:
- Sort both strings and compare them.

Optimal:
- Count character frequencies using a fixed-size array.

Time Complexity : O(n)
Space Complexity: O(1)   // 26 fixed-size array
*/