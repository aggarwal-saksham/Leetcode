/*
 * Problem #860: Lemonade Change
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: java
 * Date: 12/31/2024, 3:37:40 PM
 * Link: https://leetcode.com/problems/lemonade-change/
 */

class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five_dollars = 0, ten_dollars = 0;

        for (int x : bills) {
            if (x == 5) {
                five_dollars++;
            } else if (x == 10) {
                if (five_dollars > 0) {
                    five_dollars--;
                    ten_dollars++;
                } else {
                    return false;
                }
            } else {
                if (five_dollars > 0 && ten_dollars > 0) {
                    five_dollars--;
                    ten_dollars--;
                } else if (five_dollars > 2) {
                    five_dollars -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
}
