/*
 * Problem #3663: Find The Least Frequent Digit
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/31/2025, 12:22:36 AM
 * Link: https://leetcode.com/problems/find-the-least-frequent-digit/
 */

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> freq;
        while(n){
            int lastD = n % 10;
            freq[lastD]++;
            n/= 10;
        }
        int ans = INT_MAX;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        for(auto it : freq){
            minH.push({it.second, it.first});
        }
        return minH.top().second;
    }
};
