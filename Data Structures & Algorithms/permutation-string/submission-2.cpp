class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0), count2(26,0);
        for(char c:s1)  {
            count1[c-'a']++;
        }
        int k=s1.size();
        for(int j=0;j<s2.size();j++)    {
            count2[s2[j]-'a']++;
            if(j>=k) {
                count2[s2[j-k]-'a']--;
            }
            if(count1==count2)  return true;
        }
        return false;
    }
};
