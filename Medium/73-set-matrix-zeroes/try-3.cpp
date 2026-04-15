/*
 * Problem #73: Set Matrix Zeroes
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 2:49:29 PM
 * Link: https://leetcode.com/problems/set-matrix-zeroes/
 */

class Solution {
public:
    /* humne extra row or extra col ki jagah 0th row and
     0th col ko hi extra ki trh use kiya.
      Also [0][0] do baar traverse na ho
     isliye ek extra col ka use kiya */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int extracol = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0) {

                        matrix[0][j] = 0;
                    } else
                        extracol = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if (extracol == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
