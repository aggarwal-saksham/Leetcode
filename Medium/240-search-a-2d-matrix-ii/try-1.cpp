/*
 * Problem #240: Search a 2D Matrix II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/4/2024, 7:45:48 PM
 * Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0,col = n - 1;
        while(row < m && col >=0)
        {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col-- ;
        }
        return false;
    }
};
