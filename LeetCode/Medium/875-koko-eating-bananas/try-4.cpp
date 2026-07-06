/*
 * Problem #875: Koko Eating Bananas
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2026, 10:42:54 PM
 * Link: https://leetcode.com/problems/koko-eating-bananas/
 */

class Solution {
public:
    long long check(vector<int>& piles, int mid){
        long long total_hrs = 0;
        for(int p : piles){
            total_hrs += ceil((double)p / mid);
        }
        return total_hrs;
    }
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int n = piles.size();
        int l = 1, h = *max_element(piles.begin(), piles.end());
        while(l <= h){
            int mid = l + (h - l) / 2;
            long long total_hrs = check(piles, mid);

            if(total_hrs <= hrs){
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return l;
    }
};
