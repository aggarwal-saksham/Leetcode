/*
 * Problem #2657: Find the Prefix Common Array of Two Arrays
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/14/2025, 12:15:33 PM
 * Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 */

class Solution
{
    public:
        vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
        {
            int n = A.size();
            vector<int> ans;
            // if(A[0] == B[0]) ans.push_back(1);
            // else ans.push_back(0);
            for (int i = 0; i < n; i++)
            {
                unordered_map<int, int> mpp;
                for (int j = 0; j <= i; j++)
                {
                    mpp[A[j]]++;
                    mpp[B[j]]++;
                }
                int cnt = 0;
                for (auto i: mpp)
                {
                    if (i.second == 2) cnt++;
                }
                ans.push_back(cnt);
            }
            return ans;
        }
};
