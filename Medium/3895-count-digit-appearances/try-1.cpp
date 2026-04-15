/*
 * Problem #3895: Count Digit Appearances
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 4/13/2026, 7:58:10 PM
 * Link: https://leetcode.com/problems/count-digit-appearances/
 */

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(int n : nums){
            while(n > 0){
                    int last = n % 10;
                if(last == digit) ans++;
                n /= 10;
            }
            
        }
        return ans;
    }
};
