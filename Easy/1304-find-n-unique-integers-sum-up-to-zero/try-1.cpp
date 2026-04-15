/*
 * Problem #1304: Find N Unique Integers Sum up to Zero
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/7/2025, 7:24:16 PM
 * Link: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
 */

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int temp = n+1;
        for(int i=0 ; i<n/2 ; i++){
            ans.push_back(temp);
            ans.push_back(-temp);
            temp--;
        }
        if(n%2!=0){
           ans.push_back(0);

        }
        return ans;
    }
};
