/*
 * Problem #155: Min Stack
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/3/2026, 3:19:04 PM
 * Link: https://leetcode.com/problems/min-stack/
 */

class MinStack {
public:
    stack<long long> st;
    long long mini = LLONG_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
       if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val > mini) st.push(val);
            else
            {
                st.push(2LL *val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) mini = 2LL * mini - x;
    }
    
    int top() {
        return (st.top() > mini) ? st.top() : mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
