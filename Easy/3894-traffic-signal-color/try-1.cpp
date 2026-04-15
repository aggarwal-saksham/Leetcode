/*
 * Problem #3894: Traffic Signal Color
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 4/13/2026, 7:56:09 PM
 * Link: https://leetcode.com/problems/traffic-signal-color/
 */

class Solution {
public:
    string trafficSignal(int timer) {
       if(timer == 0) return "Green";
else if (timer == 30) return "Orange";
else if(timer > 30 && timer <= 90)return  "Red";
        return "Invalid";
    }
};
