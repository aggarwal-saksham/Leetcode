/*
 * Problem #1475: Final Prices With a Special Discount in a Shop
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2025, 3:52:25 AM
 * Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // use nse
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n, 0);

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(prices[i]);
        }

        for(int i = 0; i < n; i++){
            ans[i] = prices[i] - ans[i];
        }

        return ans;
    }
};
