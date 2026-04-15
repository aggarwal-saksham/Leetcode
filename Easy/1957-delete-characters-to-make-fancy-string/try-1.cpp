/*
 * Problem #1957: Delete Characters to Make Fancy String
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/21/2025, 2:59:41 PM
 * Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/
 */

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 1;
        for(char c : s){
            if(ans != "" && ans.back() == c){
                cnt++;
                if(cnt < 3){
                    ans += c;
                }
            }
            else {
                cnt = 1;
                ans += c;
            }
        }
        return ans;
    }
};
