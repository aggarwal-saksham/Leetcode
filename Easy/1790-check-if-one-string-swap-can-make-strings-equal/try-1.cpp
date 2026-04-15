/*
 * Problem #1790: Check if One String Swap Can Make Strings Equal
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/5/2025, 1:48:41 PM
 * Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
 */

class Solution
{
    public:
        bool areAlmostEqual(string s1, string s2)
        {
            int cnt = 0;

            for (int i = 0; i < s1.length(); i++)
            {

                if (s1[i] != s2[i])
                    cnt++;
            }

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            if (s1 == s2)
            {
                if (cnt <= 2)
                    return true;
            }

            return false;
        }
};
