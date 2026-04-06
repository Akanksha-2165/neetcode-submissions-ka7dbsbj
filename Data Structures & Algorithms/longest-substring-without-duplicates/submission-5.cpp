class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1)   return 1;
        vector<int> last_occur(256,-1);
        int maxlen=0,left=-1;
        for(int right=0;right<s.length();right++)   {
            char curr=s[right];
            if(last_occur[curr]>=left)  {
                left=last_occur[curr]++;
            }
            last_occur[curr]=right;
            maxlen=max(maxlen,right-left);
        }
        return maxlen;
    }
};
