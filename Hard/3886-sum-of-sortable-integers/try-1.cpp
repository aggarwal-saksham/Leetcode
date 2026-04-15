/*
 * Problem #3886: Sum of Sortable Integers
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/31/2026, 8:33:48 PM
 * Link: https://leetcode.com/problems/sum-of-sortable-integers/
 */

class Solution {
public:
    bool check(int l, int r, vector<int>& nums, int &minn) {
        int cnt = 0;
        int maxx = nums[l];

       
        if (nums[l] < minn) return false;

        for (int i = l + 1; i < r; i++) {
            if (nums[i] < minn) return false;

            if (nums[i - 1] > nums[i]) {
                cnt++;
            }

            maxx = max(maxx, nums[i]);
        }

        
        if (nums[l] < nums[r - 1]) {
            cnt++;
        }

        if (cnt > 1) return false;

        minn = maxx;

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            int i = 0;
            int minn = 0;  

            for (i = 0; i < n; i += k) {
                if (!check(i, i + k, nums, minn)) break;
            }

            if (i == n) ans += k;
        }

        return ans;
    }
};
