/*
 * Problem #1684: Count the Number of Consistent Strings
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/12/2024, 11:09:52 AM
 * Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
 */

class Solution
{
    public:
        int countConsistentStrings(string allowed, vector<string> &words)
        {
            map<char, int> charmap;
            int count = 0;
            for (char ch: allowed)
            {
                charmap[ch]++;
            }
            for (int i = 0; i < words.size(); i++)
            {
                for (char c: words[i])
                {
                    if (charmap.find(c) != charmap.end())
                    {
                        continue;
                    }
                    else
                    {
                        count++;
                        break;
                    }
                }
            }
            return (words.size() - count);
        }
};
