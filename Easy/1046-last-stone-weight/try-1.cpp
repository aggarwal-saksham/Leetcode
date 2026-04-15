/*
 * Problem #1046: Last Stone Weight
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/20/2025, 8:47:11 PM
 * Link: https://leetcode.com/problems/last-stone-weight/
 */

class Solution
{
    public:
        int lastStoneWeight(vector<int> &stones)
        {
            priority_queue<int> maxH;
            for (int i = 0; i < stones.size(); i++)
            {
                maxH.push(stones[i]);
            }
            while (maxH.size() > 1)
            {
                int x = maxH.top();
                maxH.pop();
                int y = maxH.top();
                maxH.pop();
                if (x - y != 0) maxH.push(x - y);
            }
            if (maxH.size() == 1) return maxH.top();
            return 0;
        }
};
