/*
 * Problem #73: Set Matrix Zeroes
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 2:07:57 PM
 * Link: https://leetcode.com/problems/set-matrix-zeroes/
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row0(m, 0), col0(n, 0);

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row0[i] = 1;
                    col0[j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(row0[i] == 1 || col0[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
