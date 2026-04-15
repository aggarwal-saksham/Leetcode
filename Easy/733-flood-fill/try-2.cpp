/*
 * Problem #733: Flood Fill
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/11/2025, 4:51:18 PM
 * Link: https://leetcode.com/problems/flood-fill/
 */

class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,
             vector<vector<int>>& copy, int init, int delrow[], int delcol[],
             int m, int n) {
        copy[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    copy[nrow][ncol] != color && image[nrow][ncol] == init) {
                    copy[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
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

        bfs(image, sr, sc, color, copy, init, delrow, delcol, m, n);

        return copy;
    }
};
