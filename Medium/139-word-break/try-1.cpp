/*
 * Problem #139: Word Break
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/9/2026, 1:45:00 AM
 * Link: https://leetcode.com/problems/word-break/
 */

class Solution {
public:
    bool backtrack(string& s, unordered_set<string>& dict, int idx,
                   vector<int>& dp) {

        if(idx == s.size()) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int j = 1; j <= s.size() - idx; j++) {

            string sub = s.substr(idx, j);

            if(dict.find(sub) != dict.end()) {
                if(backtrack(s, dict, idx + j, dp))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict;
        for(auto w : wordDict) dict.insert(w);

        vector<int> dp(s.size(), -1);

        return backtrack(s, dict, 0, dp);
    }
};
