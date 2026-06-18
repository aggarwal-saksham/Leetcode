/*
 * Problem #733: Flood Fill
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/17/2026, 11:44:17 PM
 * Link: https://leetcode.com/problems/flood-fill/
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); 
        int m = image[0].size();

        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, -1, 0, 1};

        queue<pair<int, int>> q;

        int og = image[sr][sc];

        if(og == color) return image;

        image[sr][sc] = color;
        q.push({sr, sc});

        while(!q.empty()){           
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + delx[i];
                int ny = y + dely[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == og) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
            
        }
        return image;
    }
};
