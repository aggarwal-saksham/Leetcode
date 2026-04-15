/*
 * Problem #155: Min Stack
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/25/2024, 5:35:01 PM
 * Link: https://leetcode.com/problems/min-stack/
 */

class MinStack
{
    public:
        stack<long long> st;
    long long mini = LONG_MAX;

    MinStack() {}

    void push(int val)
    {
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

    void pop()
    {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < mini) mini = 2LL *mini - x;
    }

    int top()
    {
        if (st.top() > mini) return st.top();
        else return mini;
    }

    int getMin()
    {
        return mini;
    }
};

/**
 *Your MinStack object will be instantiated and called as such:
 *MinStack* obj = new MinStack();
 *obj->push(val);
 *obj->pop();
 *int param_3 = obj->top();
 *int param_4 = obj->getMin();
 */
