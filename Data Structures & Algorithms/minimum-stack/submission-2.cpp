class MinStack {
    stack<long long> st;
    long long minStk;
public:
    MinStack() {}

    void push(int val) {
        if(!st.empty() && val< minStk)  {
            st.push(2LL *val - minStk);
            minStk= val;
        }
        else if(st.empty()) {
            st.push(val);
            minStk= val;
        }
        else
            st.push(val);   
    }
    void pop() {
        if(!st.empty() && st.top() < minStk)    {
            minStk= minStk*2 - st.top();
            st.pop(); 
        }
        else if(st.top() >= minStk)
            st.pop();        
    }
    int top() {
        if(st.top() < minStk)
            return minStk;
        else 
            return st.top();        
    }
    int getMin() {
        return minStk;   
    }
};

// BRUTE:
// Use one stack.
// getMin() scans the entire stack to find the minimum.
//Time: Push O(1), Pop O(1), Top O(1), GetMin O(n)
//Space: O(n)

//BETTER:                 LEETCODE
// Use two stacks.
// Main stack stores all values.
// Min stack stores the minimum value up to each position.
// On every push/pop, update both stacks.
// The top of the min stack is always the current minimum.
//Time: O(1) for all operations    Space: O(n) (extra min stack)

//OPTIMAL (moslty not expected)   NEETCODE
//Use one stack and one variable (minEle).
// When a new minimum is pushed, store an encoded value instead.
// If the top is encoded, decode it while popping to recover
// the previous minimum.
// This removes the need for a second stack.
//Time: O(1) for all operations      Space: O(n) (single stack + O(1) extra variable)