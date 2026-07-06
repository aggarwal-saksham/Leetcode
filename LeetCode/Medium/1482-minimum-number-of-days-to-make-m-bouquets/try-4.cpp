/*
 * Problem #1482: Minimum Number of Days to Make m Bouquets
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2026, 11:10:28 PM
 * Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 */

class Solution {
public:
    bool check(vector<int>& nums, int m, int k, int mid){
        int cnt = 0;
        for(int d : nums){
            if(d <= mid) cnt++;
            else cnt = 0;
            if(cnt == k){
                m--;
                cnt = 0;
            } 
        }
        return (m <= 0);
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if(m * 1LL * k > n) return -1;
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());
        while(l <= h){
            int mid = (l + h) / 2;
            bool possible = check(nums, m, k, mid);
            if(possible){
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return l;
    }
};
