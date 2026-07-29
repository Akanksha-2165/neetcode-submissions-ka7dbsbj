class MinStack {
    stack<long long> st;
    long long minStk;

public:
    MinStack() {
    }
    
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
