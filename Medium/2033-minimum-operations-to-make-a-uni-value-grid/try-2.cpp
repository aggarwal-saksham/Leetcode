/*
 * Problem #2033: Minimum Operations to Make a Uni-Value Grid
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2025, 5:29:05 PM
 * Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
 */

class Solution {
public:
    int findMedian(vector<vector<int>>& grid){
        vector<int> arr; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0;j < grid[0].size(); j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];
        return median;        
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        int median = findMedian(grid);
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((grid[i][j] - median) % x != 0) return -1;

                ans += abs(grid[i][j] - median) / x;
            }
        }

        return ans;
    }
};
