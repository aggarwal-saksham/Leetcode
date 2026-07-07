/*
 * Problem #4: Median of Two Sorted Arrays
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/7/2026, 1:58:31 AM
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int l = 0, h = n1;
        int left = (n1 + n2 + 1) / 2;

        while(l <= h){
            int mid1 = l + (h - l) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 - 1 >= 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 - 1 >= 0) ? nums2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                if((n1 + n2) % 2 == 1) return max(l1, l2);
                else return (double)(max(l1, l2) + min(r1, r2)) / 2;
            }
            else if(l1 > r2) h = mid1 - 1;
            else l = mid1 + 1;
        }
        return 0;
    }
};
