/*
 * Problem #721: Accounts Merge
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/27/2026, 5:11:38 PM
 * Link: https://leetcode.com/problems/accounts-merge/
 */

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.count(mail)){
                    ds.unionBySize(i, mpp[mail]);
                }
                else mpp[mail] = i;
            }
        }

        vector<vector<string>> merged(n);
        for(auto it : mpp){
            int p = it.second;
            string mail = it.first;
            int up = ds.findUPar(p);
            merged[up].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i = 0; i < n; i++){
            if(merged[i].size() == 0) continue;
            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            temp.insert(temp.end(), merged[i].begin(), merged[i].end());

            res.push_back(temp);
        }

        return res;


    }
};
