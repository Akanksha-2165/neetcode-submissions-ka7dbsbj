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

//BRUTE
// Treat every bar as the smallest bar in the rectangle.
// Expand to the left and right until a smaller bar is found.
// Compute the maximum rectangle for each bar and return the largest area.
// Time Complexity: O(n²)   Space Complexity: O(1)

//BETTER (Precompute Previous & Next Smaller)
// For every bar, find the first smaller bar on the left and right.
// These boundaries determine the maximum width for which the current
// bar is the minimum height.
// Compute area = height × width for every bar.
// Time Complexity: O(n)   Space Complexity: O(n)

//Note: This approach uses two arrays (prevSmaller[] and nextSmaller[]) and is often called the "better" solution. It still uses monotonic stacks to fill those arrays.

//OPTIMAL (Single Monotonic Stack) ⭐
// Maintain a monotonically increasing stack of indices.
// When a smaller bar is encountered, the taller bars on the stack
// can no longer extend further to the right.
// Pop each taller bar, compute its maximum rectangle using:
//   Height = popped bar
//   Right boundary = current index
//   Left boundary = new stack top after popping
// Process the remaining bars after traversal using the array end
// as the right boundary.
// Time Complexity: O(n)    Space Complexity: O(n)
