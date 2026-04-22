class Solution {
public:

    vector<string> ans;
    vector<string> mapping={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void solve(string &digits,string &cur,int index) {
        if(index==digits.size())   {
            ans.push_back(cur);
            return;
        }
        char digit=digits[index];
        string letters= mapping[digit-'0'];
        for(char ch : letters)  {
            cur.push_back(ch);
            solve(digits,cur,index+1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {} ;
        string cur;
        solve(digits,cur,0);
        return ans;
    }
};