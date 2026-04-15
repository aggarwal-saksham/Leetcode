/*
 * Problem #3643: Flip Square Submatrix Vertically
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/6/2025, 1:37:20 AM
 * Link: https://leetcode.com/problems/flip-square-submatrix-vertically/
 */

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        /*
        [[6,16,14],
        [1,2,19],
        [14,17,15],
        [18,7,6],
        [14,12,5]]
        */
        for(int i = x; i < x + k / 2; i++){
            for(int j = y; j < y + k; j++){
                swap(grid[i][j], grid[x + k - 1 - (i - x)][j]);
            }
        }
        return grid;
    }
};
