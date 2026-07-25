/*
 * Problem #218: The Skyline Problem
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/23/2026, 4:47:01 PM
 * Link: https://leetcode.com/problems/the-skyline-problem/
 */

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];

        return a[1] > b[1];
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> edge;

        for (int i = 0; i < buildings.size(); i++) {
            int s = buildings[i][0];
            int e = buildings[i][1];
            int h = buildings[i][2];

            edge.push_back({s, h, 0});
            edge.push_back({e, h, 1});
        }

        sort(edge.begin(), edge.end(), cmp);

        priority_queue<int> pq;
        unordered_map<int, int> exists;

        vector<vector<int>> skyline;
        int prev = 0;

        for (int i = 0; i < edge.size();) {
            int x = edge[i][0];

            while (i < edge.size() && edge[i][0] == x) {
                int h = edge[i][1];
                int type = edge[i][2];

                if (type == 0) {
                    pq.push(h);
                    exists[h]++;
                } else {
                    exists[h]--;
                }

                i++;
            }

            while (!pq.empty() && exists[pq.top()] == 0)
                pq.pop();

            int curr = pq.empty() ? 0 : pq.top();

            if (curr != prev) {
                skyline.push_back({x, curr});
                prev = curr;
            }
        }

        return skyline;
    }
};
