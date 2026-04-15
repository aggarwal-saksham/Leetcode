/*
 * Problem #3843: First Element with Unique Frequency
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 2/17/2026, 1:03:37 AM
 * Link: https://leetcode.com/problems/first-element-with-unique-frequency/
 */

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        unordered_map<int,int> cnt;
        for(auto it : freq){
            cnt[it.second]++;
        }

        for(int x : nums){
            if(cnt[freq[x]] == 1){
                return x;
            }
        }
        return -1;
    }
};

