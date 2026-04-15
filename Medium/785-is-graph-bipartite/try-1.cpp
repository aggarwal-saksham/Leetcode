/*
 * Problem #785: Is Graph Bipartite?
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/12/2025, 1:57:49 PM
 * Link: https://leetcode.com/problems/is-graph-bipartite/
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // not visited

                queue<int> q;
                q.push(i);
                color[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    int currColor = color[node];

                    for (auto it : graph[node]) {
                        if (color[it] != -1) {
                            if (color[it] == currColor)
                                return false;
                        }

                        else {
                            (currColor == 1) ? color[it] = 0 : color[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }

        return true;
    }
};
