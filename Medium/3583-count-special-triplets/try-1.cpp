/*
 * Problem #3583: Count Special Triplets
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/15/2025, 6:28:36 PM
 * Link: https://leetcode.com/problems/count-special-triplets/
 */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        unordered_map<int, int> prev;
        unordered_map<int, int> next;
        for (int k = 0; k < n; k++) {
            next[nums[k]]++;
        }

        for (int j = 0; j < n; j++) {
            long long cnt1 = 0, cnt2 = 0;
            next[nums[j]]--;

            cnt1 = prev[nums[j] * 2];
            cnt2 = next[nums[j] * 2];
        
            prev[nums[j]]++;

            cnt += cnt1 * cnt2;
            cnt = cnt % int(pow(10, 9) + 7);
        }

        return cnt;
    }
};
