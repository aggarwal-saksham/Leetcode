/*
 * Problem #875: Koko Eating Bananas
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/2/2026, 6:54:00 PM
 * Link: https://leetcode.com/problems/koko-eating-bananas/
 */

class Solution {
public:
    int find_max_pile(vector<int>& piles) {
        int max_pile = INT_MIN;

        int n = piles.size();
        for (int i = 0; i < n; i++) {
            max_pile = max(max_pile, piles[i]);
        }
        return max_pile;
    }

    long long calc_total_hrs(vector<int>& piles, int k) {
        int n = piles.size();
        long long total_hrs = 0;
        for (int i = 0; i < n; i++) {
            total_hrs += ceil(piles[i] / (double)k);
        }
        return total_hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = accumulate(piles.begin(), piles.end(), 0LL);
int low = (sum + h - 1) / h,
            high = find_max_pile(piles);
        while (low <= high) {
            int mid = (low + high) / 2;
            long long total_hrs = calc_total_hrs(piles, mid);
            if (total_hrs <= h) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};
