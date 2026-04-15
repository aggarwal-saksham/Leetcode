/*
 * Problem #49: Group Anagrams
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/9/2025, 7:20:38 PM
 * Link: https://leetcode.com/problems/group-anagrams/
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mpp[s].push_back(strs[i]);
        }
        for (auto i : mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
