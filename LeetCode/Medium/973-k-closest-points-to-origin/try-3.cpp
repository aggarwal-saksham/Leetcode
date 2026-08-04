/*
 * Problem #973: K Closest Points to Origin
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 8/4/2026, 5:45:24 PM
 * Link: https://leetcode.com/problems/k-closest-points-to-origin/
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> maxH;
        for(int i = 0; i < points.size(); i++){
            maxH.push({(pow(points[i][0],2) + pow(points[i][1],2)), i});
            if(maxH.size() > k){
                maxH.pop();
            }

        }

        vector<vector<int>> ans;

        while(!maxH.empty()){
            auto[_, idx] = maxH.top();
            ans.push_back(points[idx]);
            maxH.pop();
        }

        return ans;        
    }
};
