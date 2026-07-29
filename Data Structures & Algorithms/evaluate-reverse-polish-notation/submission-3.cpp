class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans=0;
        for(int i=0; i<tokens.size(); i++)  {
            
            string token= tokens[i];
            if(token == "+" || token == "-" || token == "*" || token == "/")    {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if(token == "+")    
                    ans= b+a;
                else if(token == "-")   
                    ans= b-a;
                
                else if(token == "/")   
                    ans= b/a;
                
                else    
                    ans= b*a;

                st.push(ans);                
            }

            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

// Reverse Polish (Postfix) notation places operators after operands.
// Use a stack to store operands.
// When an operator is encountered, pop the top two operands,
// evaluate the expression, and push the result back.
// The final value left in the stack is the answer.
//Time: O(n)          Space: O(n)
