/*
 * Problem #4011: Count Subarrays With Even Odd Ratio I
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/2/2026, 3:05:57 PM
 * Link: https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/
 */

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n =nums.size();
        int cnt = 0;
        double ab = 1.0 * a / b;
        for(int i = 0; i < n; i++){
            double x = 0, y = 0;
            for(int j = i; j < n; j++){
                if(nums[j] % 2 == 0) {
                    x++;
                }
                else y++;
                double xy = x / y;
                //cout << xy << endl;
                if(y > 0 && xy <= ab) cnt++;
                //cout << cnt << endl;
                
            }
        }
        return cnt;
    }
};
