/*
 * Problem #3850: Count Sequences to K
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2026, 5:08:34 PM
 * Link: https://leetcode.com/problems/count-sequences-to-k/
 */

class Solution {
public:
    long long target2 = 0, target3 = 0, target5 = 0;
    vector<vector<int>> pf;
    int n;
    
    map<tuple<int,int,int,int>, long long> dp;
    
    long long solve(int i, int e2, int e3, int e5) {
        if(i == n) {
            return (e2 == target2 && e3 == target3 && e5 == target5);
        }
        
        auto key = make_tuple(i, e2, e3, e5);
        if(dp.count(key)) return dp[key];
        
        long long ans = 0;
        
        // multiply
        ans += solve(i+1, e2 + pf[i][0], e3 + pf[i][1], e5 + pf[i][2]);
        
        // divide
        ans += solve(i+1, e2 - pf[i][0], e3 - pf[i][1], e5 - pf[i][2]);
        
        // skip
        ans += solve(i+1, e2, e3, e5);
        
        return dp[key] = ans;
    }
    
    long long countSequences(vector<int>& nums, long long k) {
        n = nums.size();
        
        // factorize k
        while(k % 2 == 0) { target2++; k /= 2; }
        while(k % 3 == 0) { target3++; k /= 3; }
        while(k % 5 == 0) { target5++; k /= 5; }
        
        if(k != 1) return 0; // contains other primes
        
        // precompute prime factors for nums
        pf.resize(n, vector<int>(3,0));
        for(int i=0;i<n;i++){
            int x = nums[i];
            while(x % 2 == 0){ pf[i][0]++; x/=2; }
            while(x % 3 == 0){ pf[i][1]++; x/=3; }
            while(x % 5 == 0){ pf[i][2]++; x/=5; }
        }
        
        return solve(0,0,0,0);
    }
};
