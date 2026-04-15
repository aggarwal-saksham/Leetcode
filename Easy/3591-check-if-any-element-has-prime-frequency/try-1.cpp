/*
 * Problem #3591: Check if Any Element Has Prime Frequency
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/23/2025, 12:44:15 AM
 * Link: https://leetcode.com/problems/check-if-any-element-has-prime-frequency/
 */

class Solution {
public:
    bool isPrime(int n){
        int cnt = 0;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0) {
                cnt++;     
                if(n / i != i){
                    cnt++;
                } 
            }      
        }

        return (cnt == 2) ? true : false;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        for(auto it : freq){
            if(isPrime(it.second)) return true;
        }

        return false;
    }
};
