/*
 * Problem #3881: Direction Assignments with Exactly K Visible People
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/28/2026, 8:17:33 PM
 * Link: https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/
 */

class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r) {
        if (r > n)
            return 0;

        vector<long long> fact(n + 1), invFact(n + 1);
        fact[0] = 1;

        for (int i = 1; i <= n; i++)
            fact[i] = (fact[i - 1] * i) % MOD;

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n - 1; i >= 0; i--)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;

        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }
    int countVisiblePeople(int n, int pos, int k) {
        if (k > n - 1)
            return 0;

        int people = n - 1;

        long long ways = nCr(people, k);

        ways = (ways * 2) % MOD;

        return (int)ways;
    }
};
