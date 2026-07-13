/*
 * Problem #278: First Bad Version
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/9/2026, 12:35:46 AM
 * Link: https://leetcode.com/problems/first-bad-version/
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while(n--){
            if(!isBadVersion(n)) break;
        }
        return n + 1;
    }
};
