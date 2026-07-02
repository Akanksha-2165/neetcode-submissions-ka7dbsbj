class Solution {
public:
/*
    //EXPAND AROUND THE CENTER
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
*/
    int countSubstrings(string s)   {
        int n=s.size(), count=0;
        vector<vector<bool>> dp(n, vector<bool>(n,false));

        for(int i=n-1; i>=0; i--)   {
            for(int j=i; j<n; j++)  {
                if(s[i]==s[j] &&
                    (j-i <=1 || dp[i+1][j-1]))  {

                        dp[i][j]=true;
                        count ++;
                    }
            }
        }
        return count;
    }
};