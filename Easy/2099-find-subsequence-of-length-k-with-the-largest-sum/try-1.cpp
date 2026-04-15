/*
 * Problem #2099: Find Subsequence of Length K With the Largest Sum
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2025, 1:39:24 PM
 * Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
 */

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<pair<int, int>> arr2;

        for (int i = n - k; i < n; i++) {
            arr2.push_back({arr[i].second, arr[i].first});
        }

        sort(arr2.begin(), arr2.end());

        vector<int> ans;

        for (auto i : arr2) {
            ans.push_back(i.second);
        }

        return ans;
    }
};
