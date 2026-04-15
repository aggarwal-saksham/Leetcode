/*
 * Problem #1903: Largest Odd Number in String
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/16/2024, 1:03:04 AM
 * Link: https://leetcode.com/problems/largest-odd-number-in-string/
 */

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string result;
        int index = -1;
        if (int(num[n - 1]) % 2 == 1) {
            result = num;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (int(num[i]) % 2 == 1) {
                index = i;
                break;
            } else
                index = -1;
        }

        if (index == -1){

            result = ' ';
        }
        result = num.substr(0, index + 1);

        return result;
    }
};
