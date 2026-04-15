/*
 * Problem #1899: Merge Triplets to Form Target Triplet
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/8/2026, 2:47:29 PM
 * Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
 */

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a1 = 0, a2 = 0, a3= 0;
        for (auto t : triplets) {
            if ((t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]) ||
                (t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2]) ||
                (t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2])) {
                a1 = max(a1, t[0]);
                a2 = max(a2, t[1]);
                a3 = max(a3, t[2]);
            }
        }
        return (vector<int>{a1, a2, a3} == target);
    }
};
