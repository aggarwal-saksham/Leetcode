/*
 * Problem #1358: Number of Substrings Containing All Three Characters
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/16/2026, 2:17:28 PM
 * Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, ans = 0, n = s.size();
        int a = 0, b = 0, c = 0;
        while(r < n){
            if(s[r] == 'a') a++;
            else if(s[r] == 'b') b++;
            else c++;

            while(a && b && c){
                ans += n - r;
                if(s[l] == 'a') a--;
                else if(s[l] == 'b') b--;
                else c--;

                l++;
            }
            r++;
        }
        return ans;
    }
};
