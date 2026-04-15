/*
 * Problem #58: Length of Last Word
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/4/2025, 1:15:33 AM
 * Link: https://leetcode.com/problems/length-of-last-word/
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;
        int cnt = 0;
        
            while(i >= 0 && s[i] == ' ') i--;
            int j = i;
            while(j >= 0 &&  s[j] != ' '){
                cnt++;
                j--;
            }
         
        return cnt;
    }
};
