/*
 * Problem #2579: Count Total Number of Colored Cells
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/12/2025, 1:19:43 PM
 * Link: https://leetcode.com/problems/count-total-number-of-colored-cells/
 */

class Solution
{
    public:
        long long coloredCells(int n)
        {
           	//1  5 13 25 41
           	// return 0;
            if (n == 1) return 1;
            long long a = (long long) n *(long long) n;
            long long b = (long long)(n - 1) *(long long)(n - 1);
            return a + b;
        }
};
