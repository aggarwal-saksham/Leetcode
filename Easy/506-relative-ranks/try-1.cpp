/*
 * Problem #506: Relative Ranks
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/21/2025, 11:32:29 PM
 * Link: https://leetcode.com/problems/relative-ranks/
 */

class Solution
{
    public:
        vector<string> findRelativeRanks(vector<int> &arr)
        {
            vector<int> brr;
            int N = arr.size();
            for (int i = 0; i < N; i++)
            {
                brr.push_back(arr[i]);
            }
            sort(brr.begin(), brr.end());
            unordered_map<int, int> mpp;
            int pos = 0;
            for (int i = 0; i < N; i++)
            {
                if (mpp[brr[i]] == 0)
                {
                    mpp[brr[i]] = pos;
                    pos++;
                }
            }

            vector<string> ans;
            for (int i = 0; i < N; i++)
            {
                if(mpp[arr[i]] == N - 1){
                    ans.push_back("Gold Medal");
                }
                else if(mpp[arr[i]] == N - 2){
                    ans.push_back("Silver Medal");
                }
                else if(mpp[arr[i]] == N - 3){
                    ans.push_back("Bronze Medal");
                }
                else{
                    int temp = N - mpp[arr[i]];
                    ans.push_back(to_string(temp));
                }
            }

            return ans;
        }
};
