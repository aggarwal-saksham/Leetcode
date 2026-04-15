/*
 * Problem #128: Longest Consecutive Sequence
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 12/29/2025, 6:39:31 PM
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num : nums){
            s.insert(num);
        }
        int ans = 0;
        for(auto it : s){
            if(s.find(it - 1) == s.end()){
                int x = it;
                int cnt = 1;
                while(s.find(x + 1) != s.end()){
                    cnt++;
                    x++;
                }

                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
