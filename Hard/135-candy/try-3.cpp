/*
 * Problem #135: Candy
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2025, 2:13:27 PM
 * Link: https://leetcode.com/problems/candy/
 */

class Solution
{
    public:
        int candy(vector<int> &ratings)
        {
            int n = ratings.size();
            int ans = 1;
            int i = 1;
           	//int peak = 0, down = 0;
            while (i < n)
            {
                if (ratings[i] == ratings[i - 1])
                {
                    ans++;
                    i++;
                    continue;
                }

                int peak = 1;
                while (i < n && ratings[i] > ratings[i - 1])
                {
                    peak++;
                    ans += peak;
                    i++;
                }

                int down = 0;
                while (i < n && ratings[i] < ratings[i - 1])
                {
                    down++;
                    ans += down;
                    i++;
                }
                down++;

                if (down > peak)
                {
                    ans += down - peak;
                }
            }
            return ans;
        }
};
