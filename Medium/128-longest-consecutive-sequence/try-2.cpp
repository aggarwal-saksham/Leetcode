/*
 * Problem #128: Longest Consecutive Sequence
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 6:44:12 PM
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }

        int ans = 0;

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int x = it;
                int cnt = 1;
                while(st.find(x + 1) != st.end()){
                        cnt++;
                        x++;
                    
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
