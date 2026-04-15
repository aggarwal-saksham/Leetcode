/*
 * Problem #1441: Build an Array With Stack Operations
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/18/2025, 9:06:16 PM
 * Link: https://leetcode.com/problems/build-an-array-with-stack-operations/
 */

class Solution
{
    public:
        vector<string> buildArray(vector<int> &target, int n)
        {
            vector<string> ans;
            int p = 0;
            for (int i = 1; i<= n; i++)
            {
                if (i == target[p])
                {
                    ans.push_back("Push");
                    p++;
                }
                else
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
                if (p == target.size()) break;
            }
            return ans;
        }
};
