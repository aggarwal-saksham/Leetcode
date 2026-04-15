/*
 * Problem #3483: Unique 3-Digit Even Numbers
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/15/2025, 8:10:34 PM
 * Link: https://leetcode.com/problems/unique-3-digit-even-numbers/
 */

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        //int count = 0;
        int n = digits.size();
        unordered_set<int> freq_uniq;

        
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue; 
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0) { 
                        freq_uniq.insert(num);
                    }
                }
            }
        }
        return freq_uniq.size();
    }
};
