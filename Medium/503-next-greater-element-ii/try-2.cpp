/*
 * Problem #503: Next Greater Element II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/25/2025, 9:09:00 PM
 * Link: https://leetcode.com/problems/next-greater-element-ii/
 */

class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            stack<int> st;
            int n = nums.size();
            vector<int> nge(n, -1);

            for (int i = 2 *n - 1; i >= 0; i--)
            {
                while (!st.empty() && st.top() <= nums[i % n])
                {
                    st.pop();
                }
                if (i < n)
                {
                    if (!st.empty())
                    {
                        nge[i] = st.top();
                    }
                }

                st.push(nums[i % n]);
            }
            return nge;
        }
};
