/*
 * Problem #1291: Sequential Digits
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2026, 2:47:08 PM
 * Link: https://leetcode.com/problems/sequential-digits/
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        int l = lower_bound(res.begin(), res.end(), low) - res.begin();
        int h = upper_bound(res.begin(), res.end(), high) - res.begin() - 1;

        return vector<int>(res.begin() + l, res.begin() + h + 1);
    }
};
