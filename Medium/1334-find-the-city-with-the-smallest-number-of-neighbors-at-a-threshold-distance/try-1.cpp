/*
 * Problem #1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/17/2025, 2:56:35 AM
 * Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 */

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int citycount = n;
        int cityNO = -1;
        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjcity = 0; adjcity < n; adjcity++) {
                if (dist[city][adjcity] <= distanceThreshold)
                    cnt++;
            }
            if (cnt < citycount || (cnt == citycount && city > cityNO)) {
                citycount = cnt;
                cityNO = city;
            }
        }
        return cityNO;
    }
};
