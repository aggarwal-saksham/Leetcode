/*
 * Problem #733: Flood Fill
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/11/2025, 2:48:25 PM
 * Link: https://leetcode.com/problems/flood-fill/
 */

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,
             vector<vector<int>>& copy, int init, int delrow[], int delcol[],
             int m, int n) {
        copy[sr][sc] = color;

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                copy[nrow][ncol] != color && image[nrow][ncol] == init) {
                dfs(image, nrow, ncol, color, copy, init, delrow, delcol, m, n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> copy = image;
        
        int init = copy[sr][sc];
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        dfs(image, sr, sc, color, copy, init, delrow, delcol, m, n);

        return copy;
    }
};
