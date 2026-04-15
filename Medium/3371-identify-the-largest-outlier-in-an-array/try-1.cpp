/*
 * Problem #3371: Identify the Largest Outlier in an Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/6/2025, 8:17:01 PM
 * Link: https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/
 */

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> mpp;
        long total = 0;
        for (int num : nums) {
            mpp[num]++;
            total += num;
        }
        int ans = INT_MIN;
        for (int num : nums) {
            int rem = total - num;
            
            if (num != rem / 2) {

                if (rem % 2 == 0 && mpp.count(rem / 2)) {
                    ans = max(ans, num);
                }
            }

            else {
                if (rem % 2 == 0 && mpp[rem / 2] > 1) {
                    ans = max(ans, num);
                }
            }
        }
        return ans;
    }
};
