/*
 * Problem #169: Majority Element
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/7/2026, 2:41:20 PM
 * Link: https://leetcode.com/problems/majority-element/
 */

class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
            int el = 0;
            int cnt = 0;
            int n = nums.size();

            for (int i = 0; i < n; i++)
            {
                if (cnt == 0)
                {
                    cnt = 1;
                    el = nums[i];
                }
                else if (el == nums[i])
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
            }
            //if no maj el exists
            // int cnt1 = 0;
            // for (int i = 0; i < n; i++)
            // {
            //     if (nums[i] == el)
            //     {
            //         cnt1++;
            //     }
            // }

            // if (cnt1 > (n / 2)) return el;
            // return -1;

            return el;
        }
};
