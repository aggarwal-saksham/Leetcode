/*
 * Problem #14: Longest Common Prefix
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/19/2025, 12:44:49 AM
 * Link: https://leetcode.com/problems/longest-common-prefix/
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        for (int i = 0; i < temp.size(); i++) {
            char c = temp[i];
            for (int j = 1; j < strs.size(); j++) {
                if(i > strs[j].size() || c != strs[j][i])
                    return temp.substr(0, i);
            }
        }
        return temp;
    }
};
