/*
 * Problem #3843: First Element with Unique Frequency
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/17/2026, 1:01:24 AM
 * Link: https://leetcode.com/problems/first-element-with-unique-frequency/
 */

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        unordered_map<int, int> mpp;
        for (auto it : freq) {
            int f = it.second;
            mpp[f]++;
        }
        set<int> y;
        for (auto j : mpp) {
            if (j.second == 1) {
                y.insert(j.first);
            }
        }
        set<int> z;
        for (auto it : freq) {
            if (y.find(it.second) != y.end())
                z.insert(it.first);
        }
        for(auto num : nums){
            if(z.find(num) != z.end()) return num;
        }
        return -1;
    }
};
