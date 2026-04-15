/*
 * Problem #278: First Bad Version
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/16/2024, 8:22:44 PM
 * Link: https://leetcode.com/problems/first-bad-version/
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    //      b
    //  1 2 3 4 5 6 7 8
    int firstBadVersion(int n) {
        long long low = 1, high = n;
        while(low <= high){
            long long mid = (low + high)/2;
            if(isBadVersion(mid) == true) high = mid - 1;
            else if (isBadVersion(mid) == false) low = mid + 1;
            if(isBadVersion(mid) == true && isBadVersion(mid - 1) == false) return mid;
        }
        return -1;
        
    }
};
