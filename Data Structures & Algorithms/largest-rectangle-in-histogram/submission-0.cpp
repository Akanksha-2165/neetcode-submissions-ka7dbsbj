class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea= 0;
        
        for(int i=0; i<heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i])    {
                //area
                int h = heights[st.top()]; //height of tower
                st.pop();                  // <-- pop first

                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;
                int area = h * w;
                maxarea = max(maxarea, area);
            }
            st.push(i);
        }
        while(!st.empty())  {
            int h= heights[st.top()];
            st.pop();

            int w;
            if (st.empty())
                w = heights.size();
            else
                w = heights.size() - st.top() - 1;
            int area = h * w;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};
