/*
 * Problem #28: Find the Index of the First Occurrence in a String
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/13/2024, 11:24:40 PM
 * Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 */

class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            int n1 = haystack.size();
            int n2 = needle.size();
            for (int i = 0; i < n1; i++)
            {
                string sub = haystack.substr(i, n2);
                if (sub == needle) return i;
            }
            return -1;
        }
};
