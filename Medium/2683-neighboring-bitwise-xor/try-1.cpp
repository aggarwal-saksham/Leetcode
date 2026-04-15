/*
 * Problem #2683: Neighboring Bitwise XOR
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/17/2025, 5:46:12 PM
 * Link: https://leetcode.com/problems/neighboring-bitwise-xor/
 */

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for(int i = 0; i < derived.size(); i++){
            xorr ^= derived[i];
        }
        if(xorr == 0) return true;
        return false;
    }
};
