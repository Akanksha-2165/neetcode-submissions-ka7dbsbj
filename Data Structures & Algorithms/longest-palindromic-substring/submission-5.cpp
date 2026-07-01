class Solution {
public:
/*
//Expand around center (interview expected)

    void expand(string &s, int left, int right, int &start, int &maxLen)    {
        
        while(left >=0 && right< s.size() && s[left]==s[right]) {
            left--;
            right++;
        }

        int len= right -left -1; // since there's extra length 

        if( len > maxLen)   {
            maxLen= len;
            start= left+1;
        }
    }

    string longestPalindrome(string s) {
        int start=0, maxLen=1;

        for(int i =0;   i< s.size(); i++)   {
            // odd length
            expand(s, i, i, start, maxLen);

            // even length
            expand(s, i, i+1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};
*/

    string longestPalindrome(string s)  {
        int n= s.size(),
        start=0,
        maxLen=1;

        vector<vector<bool>> dp (n, vector<bool>(n,false));

        for(int i=n-1; i>=0 ; i--)  {
            for(int j=i; j<n; j++)  {
                if(s[i]==s[j] &&
                    (j-i <=1 || dp[i+1][j-1]))  {
                    dp[i][j]= true;

                    if(j-i+1 > maxLen)  {
                        maxLen= j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};