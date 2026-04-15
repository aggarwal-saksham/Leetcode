/*
 * Problem #3809: Best Reachable Tower
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/17/2026, 8:12:19 PM
 * Link: https://leetcode.com/problems/best-reachable-tower/
 */

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        priority_queue<pair<int, pair<int, int>>> maxH;
        for(int i = 0; i < towers.size(); i++){
            if((abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1])) <= radius ) maxH.push({towers[i][2], {-towers[i][0], -towers[i][1]}});
               
        }

        if (maxH.empty()) return {-1, -1};

        
        return {-maxH.top().second.first, -maxH.top().second.second};
    }
};
