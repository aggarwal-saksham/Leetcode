/*
 * Problem #13: Roman to Integer
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2026, 3:57:41 PM
 * Link: https://leetcode.com/problems/roman-to-integer/
 */

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int ans = 0;
    int n = s.length();
    ans += romanMap[s[n - 1]];
    for (int i = n - 2; i >= 0 ; i--){
        if(romanMap[s[i]] < romanMap[s[i+1]]){
                ans -= romanMap[s[i]];
            }
            else{
                ans += romanMap[s[i]];
            }
        }
        return ans;
    }
};
