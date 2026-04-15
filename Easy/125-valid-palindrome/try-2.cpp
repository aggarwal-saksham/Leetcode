/*
 * Problem #125: Valid Palindrome
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/10/2024, 9:45:56 PM
 * Link: https://leetcode.com/problems/valid-palindrome/
 */

class Solution
{
    public:
        bool isPalindrome(string s)
        {
            int left = 0;
            int right = s.length() - 1;
            while (left < right)
            {
                if (!isalnum(s[left])) left++;
                else if (!isalnum(s[right])) right--;
                else if (tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
                else
                {
                    left++;
                    right--;
                }
            }
            return true;
        }
};
