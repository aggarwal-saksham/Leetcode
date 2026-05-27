/*
 * Problem #264: Ugly Number II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/14/2026, 7:06:06 PM
 * Link: https://leetcode.com/problems/ugly-number-ii/
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n+1);
    ugly[1] = 1;
    int p2=1, p3=1, p5=1;
    for (int i=2; i<=n; i++) {
        int n2=ugly[p2]*2, n3=ugly[p3]*3, n5=ugly[p5]*5;
        ugly[i] = min({n2, n3, n5});
        if (ugly[i]==n2) p2++;   // advance all matching pointers
        if (ugly[i]==n3) p3++;   // (handles duplicates like 6=2*3=3*2)
        if (ugly[i]==n5) p5++;
    }
    return ugly[n];

    }
};
