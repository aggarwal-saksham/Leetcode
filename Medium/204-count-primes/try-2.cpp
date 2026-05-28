/*
 * Problem #204: Count Primes
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 3:15:05 PM
 * Link: https://leetcode.com/problems/count-primes/
 */

class Solution {
public:
    int countPrimes(int n) {
        int primes[n+1];
        //if(n == 2) return 0;
        for(int i = 2; i <= n; i++ ){
            primes[i] = 1;
        }

        int cnt = 0;
        // TC = nlog(logn)
        for(int i = 2; i*i <= n; i++){
            
                for(int j = i*i; j <= n; j += i){
                    primes[j] = 0;
                }
            
        }

        for(int i = 2; i < n; i++ ){
            if(primes[i] == 1) cnt++;
        }

        return cnt;

        
    }
};
