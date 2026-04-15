/*
 * Problem #1726: Tuple with Same Product
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/7/2025, 7:29:45 PM
 * Link: https://leetcode.com/problems/tuple-with-same-product/
 */

class Solution
{
    public:
        int tupleSameProduct(vector<int> &nums)
        {
            unordered_map<int, int> products;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    products[nums[i] *nums[j]]++;
                }
            }

            int ans = 0;

            for (auto i: products)
            {
                if (i.second > 1) ans += (2 *i.second) *(2 *(i.second - 1));
            }

            return ans;
        }
};
