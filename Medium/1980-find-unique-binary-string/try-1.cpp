/*
 * Problem #1980: Find Unique Binary String
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/20/2025, 1:01:07 PM
 * Link: https://leetcode.com/problems/find-unique-binary-string/
 */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i = 0; i < nums.size(); i++){
            if(nums[i][i] == '0') ans += '1';
            else ans += '0';
        }
        return ans;
    }
};
