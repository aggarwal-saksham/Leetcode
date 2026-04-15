/*
 * Problem #118: Pascal's Triangle
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/25/2024, 8:51:59 PM
 * Link: https://leetcode.com/problems/pascals-triangle/
 */

class Solution
{
    public:
        vector<int> gen_row(int row)
        {
            vector<int> ans_row;
            long long ans = 1;
            ans_row.push_back(1);
            for (int col = 1; col < row; col++)
            {
                ans = ans *(row - col);	//by obs
                ans = ans / (col);
                ans_row.push_back(ans);
            }
            return ans_row;
        }
    vector<vector < int>> generate(int numRows)
    {
        vector<vector < int>> answer;
        for (int row = 1; row <= numRows; row++)
        {
            answer.push_back(gen_row(row));
        }
        return answer;
    }
};
