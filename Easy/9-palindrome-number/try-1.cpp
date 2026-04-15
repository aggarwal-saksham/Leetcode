/*
 * Problem #9: Palindrome Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2024, 1:36:31 AM
 * Link: https://leetcode.com/problems/palindrome-number/
 */

class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0) {
            return false;
        }
    int last_digit;
    long long  num;
    long long rev_num = 0;

    
    num = n;
    while ( num != 0)
    {
        last_digit = num % 10;
        num = num / 10;

        rev_num = (rev_num * 10) + last_digit;
    }
    
    return (rev_num == n);

   
    }
};
