/*
 * Problem #997: Find the Town Judge
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/17/2026, 1:32:38 PM
 * Link: https://leetcode.com/problems/find-the-town-judge/
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1)
            return 1;
        vector<int> deg(n + 1, 0);

        for (auto edge : trust) {
            deg[edge[0]]++;
            deg[edge[1]]--;
        }

        for (int i = 0; i <= n; i++) {
            if (-deg[i] == n - 1)
                return i;
        }
        return -1;
    }
};
