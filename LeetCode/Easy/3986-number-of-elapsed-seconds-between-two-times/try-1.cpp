/*
 * Problem #3986: Number of Elapsed Seconds Between Two Times
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2026, 8:08:25 AM
 * Link: https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/
 */

class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        int ans = 0;
        ans += (stoi(e.substr(0, 2)) -stoi (s.substr(0, 2))) * 60 * 60;
        ans += (stoi(e.substr(3, 2)) -stoi (s.substr(3, 2))) * 60;
        ans += (stoi(e.substr(6, 2)) -stoi (s.substr(6, 2)));
        
    return ans;
    }
};
