/*
 * Problem #3201: Find the Maximum Length of Valid Subsequence I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/16/2025, 5:21:49 PM
 * Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/
 */

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        for (int it : nums) {
            if (it % 2 == 0) cnt1++;
            else cnt2++;
        }

        int eve = 0, odd = 0;
        for (int it : nums) {
            if (it % 2 == 0)
                eve = max(eve, odd + 1);
            else
                odd = max(odd, eve + 1);
        }

        return max({cnt1, cnt2, eve, odd});
    }
};
