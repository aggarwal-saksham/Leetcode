/*
 * Problem #3847: Find the Score Difference in a Game
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/22/2026, 4:17:40 PM
 * Link: https://leetcode.com/problems/find-the-score-difference-in-a-game/
 */

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first = 0, second = 0;
        int n = nums.size(); bool flag = false;
        
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 != 0) flag = !flag;
            if((i + 1) % 6 == 0) flag = !flag;
            if(!flag) first += nums[i];
            else second += nums[i];
            
        }
        return first - second;
    }
};
