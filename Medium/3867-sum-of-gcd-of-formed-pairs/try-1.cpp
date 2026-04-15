/*
 * Problem #3867: Sum of GCD of Formed Pairs
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/20/2026, 8:04:43 PM
 * Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 */

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        vector<int> pgcd;
        for(int i = 0; i < n; i++){
            mx = max(nums[i], mx);
            pgcd.push_back(gcd(nums[i], mx));
        }

        sort(pgcd.begin(), pgcd.end());
        //for(int n : pgcd) cout << n << " ";
        int m = pgcd.size();
        int l = 0, r = m - 1;
        long long ans = 0;
        while(l < m/2){
            ans += (long long)gcd(pgcd[l], pgcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};
