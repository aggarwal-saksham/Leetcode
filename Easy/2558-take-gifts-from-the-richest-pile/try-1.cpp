/*
 * Problem #2558: Take Gifts From the Richest Pile
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/13/2024, 1:34:37 AM
 * Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/
 */

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long n = gifts.size();
        while(k>0){
        long long maxi = *max_element(gifts.begin(), gifts.end());
        long long i = distance(gifts.begin(), max_element(gifts.begin(), gifts.end()));

        cout<<maxi;
        gifts[i] = sqrt(gifts[i]);
        k--;
        }
        long long sum = accumulate(gifts.begin(), gifts.end(),0LL);
        return sum;
    }
};
