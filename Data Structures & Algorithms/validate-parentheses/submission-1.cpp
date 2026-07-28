class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++)   {

            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);

            else    {
                if(st.empty())
                    return false;

                char top=st.top();
                st.pop();

                if (s[i] == ']' && top != '[')
                    return false;
                else if (s[i] == ')' && top != '(')
                    return false;
                else if (s[i] == '}' && top != '{')
                    return false;
            }
        }
        return st.empty();
    }
};
// Intuition:
// The last opening bracket must be the first one closed,
// so we use a stack (LIFO). Push every opening bracket.
// For every closing bracket, it must match the top of the stack.
// If it doesn't, or the stack is empty, the string is invalid.
// At the end, the stack should be empty.
//TC- O(n)  SC- O(n) worst case- '((((((((('