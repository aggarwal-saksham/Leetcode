/*
 * Problem #118: Pascal's Triangle
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 12:58:54 PM
 * Link: https://leetcode.com/problems/pascals-triangle/
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n = numRows;
        for(int r = 0; r < numRows; r++){
            vector<int> row;
            for(int j = 0; j <= r; j++){
                if(j == 0 || j == r){
                    row.push_back(1);
                }

                else{
                    row.push_back(ans[r-1][j] + ans[r-1][j-1]);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
