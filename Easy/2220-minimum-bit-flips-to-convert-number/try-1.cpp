/*
 * Problem #2220: Minimum Bit Flips to Convert Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/30/2024, 1:11:35 PM
 * Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
 */

class Solution
{
    public:
        int minBitFlips(int start, int goal)
        {
            /*
            10 = 1010
            9  = 1001
            8 =  1000
            7 =  0111
            */
            int n = start ^ goal;
            int cnt = 0;
            while (n != 0)
            {
                n = n & (n - 1);
                cnt++;
            }
            return cnt;
        }
};
