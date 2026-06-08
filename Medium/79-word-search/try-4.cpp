/*
 * Problem #79: Word Search
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 5:59:03 PM
 * Link: https://leetcode.com/problems/word-search/
 */

class Solution {
public:
    bool backtrack(int idx, int row, int col, vector<vector<char>>& board, string word){
        if(idx == word.size()){
            return true;
        }
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, 1, -1};

        char temp = board[row][col];
        board[row][col] = '#';

        for(int k = 0; k < 4; k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == word[idx]){
                if(backtrack(idx + 1, nrow, ncol, board, word)) return true;
            }

        }
        board[row][col] = temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(backtrack(1, i, j, board, word)) return true;
                }
            }
        }
        return false;
    }
};
