/*
 * Problem #48: Rotate Image
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 8:52:10 PM
 * Link: https://leetcode.com/problems/rotate-image/
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        123
        456
        789

        147 transpose
        258
        369

        741 reverse
        852
        963
        */
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i > j ){
                    //i > j so that doble swapping dont happen
                    // swapping only usin lower triangle
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
