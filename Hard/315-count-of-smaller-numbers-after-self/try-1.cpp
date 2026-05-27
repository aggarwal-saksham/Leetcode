/*
 * Problem #315: Count of Smaller Numbers After Self
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/21/2026, 12:04:48 AM
 * Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 */

class Solution {
public:
    vector<int> fenTree;

    void update(int idx, int n) {
        while (idx <= n) {
            fenTree[idx]++;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;

        while (idx > 0) {
            sum += fenTree[idx];
            idx -= idx & -idx;
        }

        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int r = 1;
        for (int i = 0; i < n; i++) {
            if (!rank.count(temp[i])) {
                rank[temp[i]] = r++;
            }
        }
        int m = rank.size();
        fenTree.resize(m + 1, 0);

        vector<int> ans(nums.size());

        for (int i = n - 1; i >= 0; i--) {
            int idx = rank[nums[i]];

            ans[i] = query(idx - 1);

            update(idx, m);
        }

        return ans;
    }
};
