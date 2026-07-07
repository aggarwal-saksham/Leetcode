/*
 * Problem #1901: Find a Peak Element II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2026, 1:44:14 PM
 * Link: https://leetcode.com/problems/find-a-peak-element-ii/
 */

class Solution {
public:
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l = 0, h = n - 1;

        while(l <= h){
            int i = l + (h - l) / 2;

            int j = max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();
            bool up = (i == 0 || mat[i][j] > mat[i - 1][j]);
            bool down = (i == n - 1 || mat[i][j] > mat[i + 1][j]);

            if(up && down){
                return {i, j};
            }
            else if(i > 0 && mat[i - 1][j] > mat[i][j]){
                h = i - 1;
            }
            else{
                l = i + 1;
            }
        }

        return {-1, -1};
    }
};
