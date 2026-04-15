/*
 * Problem #763: Partition Labels
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/8/2026, 3:46:24 PM
 * Link: https://leetcode.com/problems/partition-labels/
 */

class Solution {
public:
//a: 9, b: 6, 
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, int> lastIdx;
        for(int i = 0; i < n; i++){
            lastIdx[s[i]] = i;
        }
        int maxIdx = 0;
        int lastMax = 0; 
        for(int i = 0; i < n; i++){
            maxIdx = max(maxIdx, lastIdx[s[i]]);
            if(i == maxIdx){
                ans.push_back(maxIdx - lastMax + 1);
                lastMax = maxIdx + 1;
                maxIdx = 0;
            }
        }
        return ans;
    }
};
