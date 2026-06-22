/*
 * Problem #1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2026, 2:15:03 AM
 * Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 */

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>> dist(n, vector<int> (n, 1e8));
        
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];  
            dist[it[1]][it[0]] = it[2];  
        }
        
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k]==1e8 || dist[k][j]==1e8) continue;
                    dist[i][j] = min(dist[i][j],
                    dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = 0, mini = 1e8;

        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[i][j] <= distanceThreshold) curr++;
            }
            if(curr <= mini){
                mini = curr;
                ans = i;
            }
        }

        return ans;
    }
};
