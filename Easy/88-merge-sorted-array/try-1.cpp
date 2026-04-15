/*
 * Problem #88: Merge Sorted Array
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/31/2024, 2:15:50 PM
 * Link: https://leetcode.com/problems/merge-sorted-array/
 */

class Solution
{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
           	// nums1 =[1,2,3,0,0,0]   nums2 =[2,5,6]
           	//             ^     ^                ^
           	//             i     k                j
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;

            while (i >= 0 && j >= 0)
            {
                if (nums1[i] > nums2[j])
                {
                    nums1[k] = nums1[i];
                    i--;
                }
                else
                {
                    nums1[k] = nums2[j];
                    j--;
                }
                k--;
            }

            while (j >= 0)
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
};
