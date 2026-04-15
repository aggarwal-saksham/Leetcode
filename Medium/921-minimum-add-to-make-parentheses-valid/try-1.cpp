/*
 * Problem #921: Minimum Add to Make Parentheses Valid
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/13/2024, 7:16:27 PM
 * Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, neg = 0;
        for(char c : s){
            if(c == '(') cnt++;
            if(c == ')' && cnt > 0) cnt--;
            else if(c == ')' && cnt <= 0) neg++;
    }
    int ans = cnt + neg;
    return ans;

    }
};
