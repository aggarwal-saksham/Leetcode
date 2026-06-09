/*
 * Problem #51: N-Queens
 * Difficulty: Hard
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 9:42:06 PM
 * Link: https://leetcode.com/problems/n-queens/
 */

class Solution {
public:
    void backtrack(int r, vector<string>& board, int n, vector<int>& upperCol,
                   vector<int>& upperLeft, vector<int>& upperRight,
                   vector<vector<string>>& ans) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (upperCol[c] == 0 && upperLeft[n - 1 + c - r] == 0 &&
                upperRight[r + c] == 0) {
                upperCol[c] = 1;
                upperLeft[n - 1 + c - r] = 1;
                upperRight[r + c] = 1;
                board[r][c] = 'Q';
                backtrack(r + 1, board, n, upperCol, upperLeft, upperRight,
                          ans);
                board[r][c] = '.';
                upperCol[c] = 0;
                upperLeft[n - 1 + c - r] = 0;
                upperRight[r + c] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> upperCol(n, 0), upperLeft(2 * n - 1, 0),
            upperRight(2 * n - 1, 0);
        backtrack(0, board, n, upperCol, upperLeft, upperRight, ans);
        return ans;
    }
};
