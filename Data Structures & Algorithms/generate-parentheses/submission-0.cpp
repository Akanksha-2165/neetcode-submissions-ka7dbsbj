class Solution {
public:

    vector<string> ans;

    void solve(string curr_str,int n,int open,int close) {
        if(curr_str.size()==2*n) {
            ans.push_back(curr_str);
            return;
        }
        if(open<n)  {
            curr_str.push_back('(');
            solve(curr_str,n,open+1,close);
            curr_str.pop_back();
        }
        if(close<open)  {
            curr_str.push_back(')');
            solve(curr_str,n,open,close+1);
            curr_str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr_str;
        solve(curr_str,n,0,0);
        return ans;
    }
};
