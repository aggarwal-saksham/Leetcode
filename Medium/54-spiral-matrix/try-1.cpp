/*
 * Problem #54: Spiral Matrix
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2024, 9:00:35 PM
 * Link: https://leetcode.com/problems/spiral-matrix/
 */

class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
            int n = matrix.size();
            int m = matrix[0].size();

            vector<int> ansarr;

            int top = 0, left = 0, right = m - 1, bottom = n - 1;

            while (top <= bottom && left <= right)
            {
                for (int i = left; i <= right; i++)
                {
                    ansarr.push_back(matrix[top][i]);
                }
                top++;


                for (int i = top; i <= bottom; i++)
                {
                    ansarr.push_back(matrix[i][right]);
                }
                right--;

                if(top <= bottom){
                    for(int i = right; i >= left; i--){
                        ansarr.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }
                if(left <= right){
                    for(int i = bottom; i >= top; i--){
                        ansarr.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
            return ansarr;


        }
};
