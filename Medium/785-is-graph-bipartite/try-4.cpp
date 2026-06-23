/*
 * Problem #785: Is Graph Bipartite?
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2026, 1:31:37 AM
 * Link: https://leetcode.com/problems/is-graph-bipartite/
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);


        for(int i = 0; i < n; i++){
            if(color[i] != -1) continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                int c = color[node];

                for(int nbr : graph[node]){
                    if(color[nbr] == -1){
                        color[nbr] = !c;
                        q.push(nbr);
                    }

                    else if(color[nbr] == c) return false;
                }
            }

        }
        return true;
    }
};
