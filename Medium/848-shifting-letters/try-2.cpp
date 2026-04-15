/*
 * Problem #848: Shifting Letters
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/5/2025, 11:10:10 PM
 * Link: https://leetcode.com/problems/shifting-letters/
 */

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        int sum = 0;
        //string ans = "";
        for(int i = n - 1; i >= 0; i--){
            sum += shifts[i] % 26;
            char newChar = (s[i] - 'a' + sum) % 26;
            s[i] = char(newChar + 'a');
        }
        // reverse(ans.begin(), ans.end());
        return s;
    }
};
