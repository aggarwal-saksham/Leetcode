/*
 * Problem #51: N-Queens
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2025, 2:08:42 AM
 * Link: https://leetcode.com/problems/n-queens/
 */

class Solution {
public:
    bool check(int row, int col, vector<string> board, int n) {
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while (row >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
        }

        row = duprow;
        col = dupcol;
        while (col < n && row >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col++;
            row--;
        }
        return true;
    }

    void backtrack(int r, vector<vector<string>>& ans, vector<string>& board,
                   int n) {

        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (check(r, c, board, n)) {
                board[r][c] = 'Q';
                backtrack(r + 1, ans, board, n);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string empty(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = empty;
        }

        backtrack(0, ans, board, n);
        return ans;
    }
};
