/*
 * Problem #4014: Minimum Total Price After Applying Discounts
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/9/2026, 8:25:40 PM
 * Link: https://leetcode.com/problems/minimum-total-price-after-applying-discounts/
 */

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0;
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int n = discounts.size();
        int m = prices.size();
        int i = 0;
        for(i = 0; i < min(n, m); i++){
            double p = prices[i];
            double d = discounts[i];
            ans += (p * (100 - d)) / 100;
        }
        while(i < m){
            double p = prices[i];
            ans += p;
            i++;
        }
        return ans;
    }
};
