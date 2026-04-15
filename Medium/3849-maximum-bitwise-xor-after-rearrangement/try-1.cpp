/*
 * Problem #3849: Maximum Bitwise XOR After Rearrangement
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2026, 4:45:17 PM
 * Link: https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/
 */

class Solution {
public:
    string maximumXor(string s, string t) {
        int ones = 0, zeroes = 0;
        for(char c : t){
            if(c == '1') ones++;
            else zeroes++;
        }
        string ans = "";

        for(char c : s){
            if(c == '1' && zeroes) {
                ans += '1';
                zeroes--;
            }
            else if (c == '1' && !zeroes){
                ans += '0';
                ones--;
            }
            else if (c == '0' && ones){
                ans += '1';
                ones--;
            }
            else if (c == '0' && !ones){
                ans += '0';
                zeroes--;
            }
        }
        return ans;
    }
};
