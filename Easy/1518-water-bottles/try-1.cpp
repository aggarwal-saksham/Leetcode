/*
 * Problem #1518: Water Bottles
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/1/2025, 2:41:20 PM
 * Link: https://leetcode.com/problems/water-bottles/
 */

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while(empty >= numExchange){
            empty -= numExchange * (numBottles / numExchange);
            ans += numBottles / numExchange;
            empty += numBottles / numExchange;
            numBottles = empty;
        }

        return ans;
    }
};
