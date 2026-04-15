/*
 * Problem #3854: Minimum Operations to Make Array Parity Alternating
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/28/2026, 8:54:22 PM
 * Link: https://leetcode.com/problems/minimum-operations-to-make-array-parity-alternating/
 */

class Solution {
public:

    int getParity(long long x) {
        return (int)(((x % 2) + 2) % 2);
    }

    int mismatchCount(const vector<int>& nums, int startParity) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int expected = startParity ^ (i & 1);
            if (getParity(nums[i]) != expected) cnt++;
        }
        return cnt;
    }

    long long minRangeForPattern(const vector<int>& nums, int startParity) {
        int n = nums.size();

        vector<pair<long long,int>> cand;

        for (int i = 0; i < n; i++) {
            int expected = startParity ^ (i & 1);
            bool mismatch = (getParity(nums[i]) != expected);

            if (mismatch) {
                cand.push_back({(long long)nums[i] - 1, i});
                cand.push_back({(long long)nums[i] + 1, i});
            } else {
                cand.push_back({(long long)nums[i], i});
            }
        }

        sort(cand.begin(), cand.end());

        vector<int> freq(n, 0);
        int covered = 0;
        int left = 0;
        long long best = LLONG_MAX;

        for (int right = 0; right < cand.size(); right++) {
            int idx = cand[right].second;
            if (freq[idx]++ == 0) covered++;

            while (covered == n) {
                best = min(best, cand[right].first - cand[left].first);
                int lid = cand[left].second;
                if (--freq[lid] == 0) covered--;
                left++;
            }
        }

        return best == LLONG_MAX ? 0 : best;
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {0, 0};

        int m0 = mismatchCount(nums, 0);
        int m1 = mismatchCount(nums, 1);

        int minOps = min(m0, m1);
        long long bestRange = LLONG_MAX;

        if (m0 == minOps)
            bestRange = min(bestRange, minRangeForPattern(nums, 0));

        if (m1 == minOps)
            bestRange = min(bestRange, minRangeForPattern(nums, 1));

        return {minOps, (int)bestRange};
    }
};
