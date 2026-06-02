/*
 * Problem #901: Online Stock Span
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2026, 5:38:07 PM
 * Link: https://leetcode.com/problems/online-stock-span/
 */

class StockSpanner {
public:
    typedef pair<int,int> pii;
    stack<pii> st;
    int ind = -1;
    StockSpanner() {
        ind = -1;
        while(!st.empty()){
            st.pop();
        }
    }
    
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = 0;
        if(st.empty()){
            ans = ind + 1;
        }
        else ans = ind - st.top().second;

        st.push({price, ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
