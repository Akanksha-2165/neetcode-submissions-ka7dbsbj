class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> nextGreater;
        for(int i = temperatures.size()-1; i>=0; i--)   {
                
            while(!nextGreater.empty() && temperatures[i] >= temperatures[nextGreater.top()])
                nextGreater.pop();

            if(nextGreater.empty())
                ans[i]= 0;
            else
                ans[i]= nextGreater.top()-i;

            nextGreater.push(i);
        }   
        return ans;
    }
};

//BRUTE
// For every day, scan all future days until a warmer temperature is found.
//Time: O(n²)    Space: O(1)

//Optimal (Monotonic Stack)
// Traverse from right to left.
// Maintain a decreasing stack of indices.
// Remove all temperatures that are not warmer than the current one.
// The top of the stack is the next warmer day.
// Store the distance and push the current index.
//Time: O(n)     Space: O(n)