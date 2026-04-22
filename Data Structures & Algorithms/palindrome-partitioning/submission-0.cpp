class Solution {
public:

    vector<vector<string>> ans;

    bool isPalindrome(string s,int l,int r) {
        while(l<r)  {
            if(s[l]!=s[r])  return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int index,vector<string> path, string s)  {
        if(index==s.size()) {
            ans.push_back(path);
            return;
        }

        for(int j=index;j<s.size();j++) {
            if(isPalindrome(s,index,j)) {
                string sub=s.substr(index,j-index+1);  //str.substr(start,length)
                path.push_back(sub);
                solve(j+1,path,s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(0,path,s);
        return ans;
    }
};
