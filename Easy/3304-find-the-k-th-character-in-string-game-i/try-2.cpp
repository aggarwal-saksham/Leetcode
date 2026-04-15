/*
 * Problem #3304: Find the K-th Character in String Game I
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/4/2025, 1:03:18 PM
 * Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
 */

class Solution {
public:
    int setbits(int n){
        int cnt = 0;
        while(n){
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
    char kthCharacter(int k) {
        return 'a' + setbits(k - 1);
    }
};
