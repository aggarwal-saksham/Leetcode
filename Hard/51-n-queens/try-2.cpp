/*
 * Problem #51: N-Queens
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 2/27/2026, 2:08:59 PM
 * Link: https://leetcode.com/problems/n-queens/
 */

class Solution {
public:
    bool check(int row, int col, vector<string> &board, int n) {
       for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
        }

        // Check upper left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        // Check upper right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void backtrack(int r, vector<vector<string>>& ans, vector<string>& board,
                   int n) {
        if(r == n){
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            if(check(r, c, board, n)){
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
