/*
 * Problem #2208: Minimum Operations to Halve Array Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 2/13/2025, 3:57:07 PM
 * Link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
 */

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> maxH;
        double sum = 0;
        for (int num : nums) {
            maxH.push(num);
            sum += num;
        }
        double halfsum = sum;
        int cnt = 0;
        while (!maxH.empty()) {
            cnt++;
            double x = maxH.top();
            maxH.pop();
            maxH.push(x / 2);
            halfsum -= x / 2;
            if (halfsum <= sum/2)
                return cnt;
        }
        return cnt;
    }
};
