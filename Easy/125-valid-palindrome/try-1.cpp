/*
 * Problem #125: Valid Palindrome
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/10/2024, 8:48:11 PM
 * Link: https://leetcode.com/problems/valid-palindrome/
 */

class Solution
{
    public:
        bool isPalindrome(string s)
        {
            string result;
            //string rev;
            for (char c: s)
            {
                if (isalnum(c))
                {
                    if (isupper(c))
                    {
                        c = tolower(c);
                    }
                    result += c;
                }
            }
            string result_copy = result;
            reverse(result.begin(), result.end());
            if (result == result_copy) return true;
            return false;
           	//racecarracecar
           	//getget
        }
};
