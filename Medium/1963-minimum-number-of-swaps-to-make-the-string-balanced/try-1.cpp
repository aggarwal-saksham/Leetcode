/*
 * Problem #1963: Minimum Number of Swaps to Make the String Balanced
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/8/2024, 6:26:02 PM
 * Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
 */

class Solution {
public:
    int minSwaps(string s) {
      stack<char> st;
      int n = s.size();
      for(char c : s){
        if(!st.empty() && c == ']' && st.top() == '[') st.pop();
        else st.push(c);
      }
      int pairs = st.size()/2; 
      int ans = (pairs + 1)/2;
      return ans;
    }
};
