/*
 * Problem #2525: Categorize Box According to Criteria
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/21/2026, 3:01:03 PM
 * Link: https://leetcode.com/problems/categorize-box-according-to-criteria/
 */

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        if((((long long)width * (long long)height * (long long)length *1LL) >= 1e9) || width >= 1e4 || length >= 1e4 || height >= 1e4) bulky = true;
        if(mass >= 100) heavy = true;
        if(bulky && heavy) return "Both";
        else if(!bulky && !heavy) return "Neither";
        else if(bulky && !heavy) return "Bulky";
        else return "Heavy";
    }
};
