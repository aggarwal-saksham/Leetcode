/*
 * Problem #36: Valid Sudoku
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/30/2025, 2:53:32 PM
 * Link: https://leetcode.com/problems/valid-sudoku/
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //i/3 x 3 + j/3
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> grid(9, vector<int>(9, 0));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int num = board[i][j] - '1';
                
                if(board[i][j] == '.'){
                    continue;
                }

                else if (row[i][num] || col[j][num] ||
                    grid[((i / 3) * 3 + j / 3)][num]) {
                    return false;
                }

                else {
                    row[i][num] = 1;
                    col[j][num] = 1;
                    grid[((i / 3) * 3 + j / 3)][num] = 1;
                }
            }
        }
        return true;
    }
};
