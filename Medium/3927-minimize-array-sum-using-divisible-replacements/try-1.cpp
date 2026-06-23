/*
 * Problem #3927: Minimize Array Sum Using Divisible Replacements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/20/2026, 1:59:46 AM
 * Link: https://leetcode.com/problems/minimize-array-sum-using-divisible-replacements/
 */

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        long long ans = 0;

        for(int x : nums) {
            int best = x;

            for(int d = 1; 1LL * d * d <= x; d++) {
                if(x % d) continue;

                if(st.count(d))
                    best = min(best, d);

                int other = x / d;

                if(st.count(other))
                    best = min(best, other);
            }

            ans += best;
        }

        return ans;
    }
};
