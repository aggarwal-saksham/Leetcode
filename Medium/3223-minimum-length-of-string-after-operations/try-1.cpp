/*
 * Problem #3223: Minimum Length of String After Operations
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/13/2025, 12:47:26 PM
 * Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/
 */

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        for(char c : s){
            mpp[c]++;
        }
        for(auto i : mpp){
            if(i.second > 2 && i.second % 2 == 1)
                n -= (i.second - 1);
            else if(i.second > 2 && i.second % 2 == 0)
                n -= (i.second - 2);
        }
        return n;
    }
};
