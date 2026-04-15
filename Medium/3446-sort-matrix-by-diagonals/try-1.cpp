/*
 * Problem #3446: Sort Matrix by Diagonals
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/28/2025, 10:45:45 PM
 * Link: https://leetcode.com/problems/sort-matrix-by-diagonals/
 */

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int diag = i - j;
                mpp[diag].push_back(grid[i][j]);
            }
        }

        for(auto &p : mpp){
            sort(p.second.begin(), p.second.end());
            if(p.first < 0) reverse(p.second.begin(), p.second.end());
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int diag = i - j;
                grid[i][j] = mpp[diag].back();
                mpp[diag].pop_back();
            }
        }

        return grid;
    }
};

