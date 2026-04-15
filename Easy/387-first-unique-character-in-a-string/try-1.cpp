/*
 * Problem #387: First Unique Character in a String
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/17/2024, 11:14:09 PM
 * Link: https://leetcode.com/problems/first-unique-character-in-a-string/
 */

class Solution
{
    public:
        int firstUniqChar(string s)
        {
            map<char, int> mp;
            char a;
            for (char c: s)
            {
                mp[c]++;
            }
            for (int i = 0; i < s.length(); i++)
            {
                if (mp[s[i]] == 1)
                {
                    return i;
                }
            }
            /*for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == a)
                {
                    return i;
                    break;
                }
            }*/
            return -1;
        }
};
