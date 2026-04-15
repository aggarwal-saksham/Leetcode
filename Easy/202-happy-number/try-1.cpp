/*
 * Problem #202: Happy Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/14/2025, 1:49:32 PM
 * Link: https://leetcode.com/problems/happy-number/
 */

class Solution {
public:
    // with O(n) space
    unordered_map<int ,int> mpp;
    bool isHappy(int n) {
        cout << n << "->";
        if(mpp[n] == 1) return false;
        mpp[n]++;
        int new_num = 0;
        while(n){
            new_num += pow((n % 10), 2);
            n /= 10;
        }
        if(new_num == 1) return true;


        return isHappy(new_num);
    }
};
