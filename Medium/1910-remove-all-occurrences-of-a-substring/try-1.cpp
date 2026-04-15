/*
 * Problem #1910: Remove All Occurrences of a Substring
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/11/2025, 2:42:45 PM
 * Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
 */

class Solution
{
    public:
        string removeOccurrences(string s, string part)
        {
            int n = part.size();
            while (s.find(part) != -1)
            {
                int i = s.find(part);
                if (i != -1) s.erase(i, n);
            }
            return s;
        }
};
