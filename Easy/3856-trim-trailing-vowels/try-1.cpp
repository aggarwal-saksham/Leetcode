/*
 * Problem #3856: Trim Trailing Vowels
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/1/2026, 7:16:55 PM
 * Link: https://leetcode.com/problems/trim-trailing-vowels/
 */

class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.size();
        int r = n - 1;
        while(r >= 0){
            if(s[r] == 'a' ||s[r] == 'e' ||s[r] == 'i' ||s[r] == 'o' ||s[r] == 'u'){
                r--;
            }
            else break;
        }

        return s.substr(0, r + 1);
    }
};
