/*
 * Problem #60: Permutation Sequence
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2025, 12:04:11 AM
 * Link: https://leetcode.com/problems/permutation-sequence/
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            fact *= i;
        }
        fact /= n;

        string ans = "";

        while (nums.size()) {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact));

            k = k % fact;
            if (!nums.empty())
                fact /= nums.size();
        }

        return ans;
    }
};
