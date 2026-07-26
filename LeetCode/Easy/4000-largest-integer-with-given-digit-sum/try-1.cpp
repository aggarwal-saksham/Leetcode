/*
 * Problem #4000: Largest Integer With Given Digit Sum
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/26/2026, 1:48:56 PM
 * Link: https://leetcode.com/problems/largest-integer-with-given-digit-sum/
 */

class Solution {
public:
    int largestInteger(int n, int s) {
        int ans = 0;
        while(n--){
            if(s >= 9){
                ans = ans * 10 + 9;
                s -= 9;
            }
            else{
                ans = ans * 10 + s;
                s = 0;
            }
        }
        if(s > 0) return -1;
        else return ans;
    }
};
