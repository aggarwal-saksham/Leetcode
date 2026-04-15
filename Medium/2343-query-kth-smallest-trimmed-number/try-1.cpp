/*
 * Problem #2343: Query Kth Smallest Trimmed Number
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/14/2026, 4:30:49 PM
 * Link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/
 */

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        int m = nums[0].length();
        for(auto &q : queries){
            int trim = q[1];
            int k = q[0];
            vector<pair<string, int>> trimmed;
            for (int i = 0; i < n; i++) {
                string s = nums[i].substr(nums[i].size() - trim);
                trimmed.push_back({s, i});
            }
            
            sort(trimmed.begin(), trimmed.end());
            
            ans.push_back(trimmed[k - 1].second);
        }
        return ans;
    }
};
