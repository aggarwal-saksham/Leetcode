/*
 * Problem #202: Happy Number
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/14/2025, 4:21:48 PM
 * Link: https://leetcode.com/problems/happy-number/
 */

class Solution {
public:
    // with O(1) space
    bool isHappy(int n) {
        int slow = n, fast = n;
        slow = sq(slow);
        fast = sq(sq(fast));
        while(slow != fast && fast != 1){
            slow = sq(slow);
            fast = sq(sq(fast));
        }

        return (fast == 1);
    }
    int sq(int n){
        int new_num = 0;
        while(n){
            int num = n % 10;
            new_num += num * num;
            n /= 10;
        }

        return new_num;
    }
};
