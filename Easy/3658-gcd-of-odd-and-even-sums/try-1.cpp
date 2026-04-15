/*
 * Problem #3658: GCD of Odd and Even Sums
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/26/2025, 1:52:24 AM
 * Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
 */

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        cout << sumOdd<<endl;
        int sumEven = (n * (n + 1));
        cout << sumEven;
        return gcd(sumOdd, sumEven);
    }
};
