/*
 * Problem #904: Fruit Into Baskets
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/10/2025, 9:58:23 PM
 * Link: https://leetcode.com/problems/fruit-into-baskets/
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //[1,2,3,2,3,2,3,2,4,4,4,5,5,5,4,4,3,3,2,2]
        int n = fruits.size();
        int l = 0, r = 0, maxi = 1;
        unordered_map<int, int> mpp;
        while (l <= r && r < n) {
            while (r < n && mpp.size() <= 2) {
                mpp[fruits[r]]++;
                if (mpp.size() <= 2)
                    maxi = max(maxi, r - l + 1);
                r++;
            }
            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
        }
        return maxi;
    }
};
