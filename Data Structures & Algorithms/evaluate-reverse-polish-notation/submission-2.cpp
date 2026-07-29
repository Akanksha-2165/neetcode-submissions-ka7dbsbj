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

                if(token == "+")    {
                    ans= b+a;
                    st.push(ans);
                }
                else if(token == "-")   {
                    ans= b-a;
                    st.push(ans);
                }
                else if(token == "/")   {
                    ans= b/a;
                    st.push(ans);
                }
                else    {
                    ans= b*a;
                    st.push(ans);
                }
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
