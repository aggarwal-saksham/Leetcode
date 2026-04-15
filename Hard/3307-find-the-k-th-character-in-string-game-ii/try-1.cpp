/*
 * Problem #3307: Find the K-th Character in String Game II
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/4/2025, 4:57:31 PM
 * Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/
 */

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) return 'a';

        long long len = 1;
        int ind = 0;
        while(len * 2 < k){
            len *= 2LL;
            ind++;
        }

        char c = kthCharacter(k - len, operations);

        return (operations[ind] == 0) ? c : 'a' + (c - 'a' + 1) % 26;
    }
};
