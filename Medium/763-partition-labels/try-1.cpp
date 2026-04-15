/*
 * Problem #763: Partition Labels
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 1:42:16 AM
 * Link: https://leetcode.com/problems/partition-labels/
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, int> lastIdx;
        for(int i = 0; i < n; i++){
            lastIdx[s[i]] = i;
        }

        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            r = max(r, lastIdx[s[i]]);
            if(i == r){
                ans.push_back(r - l + 1);
                l = i + 1;
            }
        }
        return ans;
    }
};
