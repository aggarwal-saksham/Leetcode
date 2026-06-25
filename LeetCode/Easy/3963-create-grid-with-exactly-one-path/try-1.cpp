/*
 * Problem #3963: Create Grid With Exactly One Path
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2026, 12:47:10 PM
 * Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
 */

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string free(n, '.');
        ans.push_back(free);
        while(m - 1 > 0){
            string next(n - 1, '#');
            next += '.';
            ans.push_back(next);
            m--;
        }
        return ans;
    }
};
