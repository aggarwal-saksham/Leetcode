/*
 * Problem #3848: Check Digitorial Permutation
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2026, 4:37:35 PM
 * Link: https://leetcode.com/problems/check-digitorial-permutation/
 */

class Solution {
public:
    int fact(int n){
        if(n == 0 || n == 1) return 1;
        int prod = 1;
        while( n > 1){
            prod *= n;
            n--;
        }
        return prod;
    }
    bool isDigitorialPermutation(int n) {
        unordered_map<int, int> mpp;
        unordered_map<int, int> mpp2;
        int copy = n;
        int sum = 0;
        while(copy > 0){
            int lastD = copy % 10;
            mpp[lastD]++;
            copy = copy / 10;
            sum += fact(lastD);
            
        }
        cout << sum;
        while(sum > 0){
            int lastD = sum % 10;
            mpp2[lastD]++;
            sum = sum / 10;
            
        }
        
        return (mpp == mpp2) ? true : false; 
    }
};
