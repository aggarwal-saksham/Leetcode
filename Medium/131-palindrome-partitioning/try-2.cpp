/*
 * Problem #131: Palindrome Partitioning
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 2/25/2026, 5:55:01 PM
 * Link: https://leetcode.com/problems/palindrome-partitioning/
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if ((s[left]) != (s[right])) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }

    void backtrack(int idx, string& s, vector<vector<string>>& ans,
                   vector<string>& part) {
        if (idx == s.size()) {
            ans.push_back(part);
            return;
        }

        for (int j = 1; j <= s.size() - idx; j++) {
            string curr = s.substr(idx, j);
            if (isPalindrome(curr)) {
                part.push_back(curr);
                backtrack(idx + j, s, ans, part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        backtrack(0, s, ans, part);
        return ans;
    }
};
