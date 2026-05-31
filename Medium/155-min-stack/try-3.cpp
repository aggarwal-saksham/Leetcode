/*
 * Problem #155: Min Stack
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/1/2026, 1:44:47 AM
 * Link: https://leetcode.com/problems/min-stack/
 */

class MinStack {
public:
    stack<long long> st;
    long long mn;

    MinStack() {}

    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mn = val;
        }
        else if(val >= mn) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mn);
            mn = val;
        }
    }

    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mn) {
            mn = 2LL * mn - x;
        }
    }

    int top() {
        long long x = st.top();

        if(x < mn) {
            return mn;
        }

        return x;
    }

    int getMin() {
        return mn;
    }
};
