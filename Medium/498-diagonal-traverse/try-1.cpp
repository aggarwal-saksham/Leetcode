/*
 * Problem #498: Diagonal Traverse
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/25/2025, 12:16:23 PM
 * Link: https://leetcode.com/problems/diagonal-traverse/
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //12345
        //12345
        /*
        
        0 - 1
        1 - 2, 4
        2 - 3, 5, 7
        3 - 6, 8
        4 - 9
        */
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mpp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        bool flag = 1;
        for(auto it : mpp){
            vector<int> x = it.second;
            if(flag){
                reverse(x.begin(), x.end());
            }
            ans.insert(ans.end(), x.begin(), x.end());
            flag = !flag;
        }

        return ans;
    }
};
