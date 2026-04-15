/*
 * Problem #78: Subsets
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 12/14/2024, 8:58:53 PM
 * Link: https://leetcode.com/problems/subsets/
 */

class Solution
{
    public:
        void helper(int i, vector<int>& arr, vector<int> subs, vector<vector<int>>&ans){
      //
      if(i == arr.size()){
          ans.push_back(subs);
          return;
      }
      //
      vector<int> subsCopy = subs;
      subsCopy.push_back(arr[i]);
      helper(i + 1, arr, subsCopy, ans);
      helper(i + 1, arr, subs, ans);
    }
        vector<vector < int>> subsets(vector<int> &arr)
        {
            vector<vector < int>> ans;
            vector<int> subs;
            helper(0, arr, subs, ans);
            return ans;
        }
};
