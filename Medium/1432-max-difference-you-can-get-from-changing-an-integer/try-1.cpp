/*
 * Problem #1432: Max Difference You Can Get From Changing an Integer
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2025, 2:45:47 PM
 * Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
 */

class Solution
{
    public:
        int maxDiff(int num)
        {
            char d1;
            string maxi = to_string(num);
            for (int i = 0; i < maxi.length(); i++)
            {
                if (maxi[i] == '9') continue;
                else
                {
                    d1 = maxi[i];
                    break;
                }
            }
            for (int i = 0; i < maxi.length(); i++)
            {
                if (maxi[i] == d1)
                {
                    maxi[i] = '9';
                }
            }

            char d2 = '1';
            int ind = -1;
            string mini = to_string(num);
            for (int i = 0; i < mini.length(); i++)
            {
                if (mini[i] == '1' || mini[i] == '0') continue;
                else
                {
                    d2 = mini[i];
                    ind = i;
                    break;
                }
            }
            if (ind == 0 || ind == -1)
            {

                for (int i = 0; i < mini.length(); i++)
                {
                    if (mini[i] == d2)
                    {
                        mini[i] = '1';
                    }
                }
            }
            else
            {
                for (int i = 0; i < mini.length(); i++)
                {
                    if (mini[i] == d2)
                    {
                        mini[i] = '0';
                    }
                }
            }

            int diff = stoi(maxi) - stoi(mini);
            return diff;
        }
};
