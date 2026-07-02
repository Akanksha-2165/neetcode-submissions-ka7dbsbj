class Solution {
public:

    void expand(string &s, int left, int right, int &count) {
        while( left>=0 && right<s.size() && s[left]==s[right] )    {
            left--;
            right++;
            count++;
        }
    }

    int countSubstrings(string s) {
        int count =0, n=s.size();

        for(int i=0; i<n; i++)  {
            //odd length
            expand(s,i,i, count);
            //even length
            expand(s,i, i+1, count);
        }
        return count;
    }
};
