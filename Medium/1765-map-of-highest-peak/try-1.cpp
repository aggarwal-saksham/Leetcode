/*
 * Problem #1765: Map of Highest Peak
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/11/2025, 9:10:23 PM
 * Link: https://leetcode.com/problems/map-of-highest-peak/
 */

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         int m = isWater.size();
        int n = isWater[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        typedef pair<pair<int, int>, int> ppi;
        queue<ppi> q;

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            q.pop();
            dist[row][col] = t;


            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        return dist;
    }
};
