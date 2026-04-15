/*
 * Problem #168: Excel Sheet Column Title
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/21/2025, 12:25:07 AM
 * Link: https://leetcode.com/problems/excel-sheet-column-title/
 */

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber--){
            ans += 'A' + (columnNumber%26);
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
