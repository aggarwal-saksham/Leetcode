/*
 * Problem #410: Split Array Largest Sum
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/20/2024, 1:19:19 AM
 * Link: https://leetcode.com/problems/split-array-largest-sum/
 */

class Solution
{
    public:
        int find_sub(vector<int> &arr, int n, int total)
        {
            int sub = 1;
            long long totalsub = 0;
            for (int i = 0; i < n; i++)
            {
                if (totalsub + arr[i] <= total)
                {
                    totalsub += arr[i];
                }
                else
                {
                    sub++;
                    totalsub = arr[i];
                }
            }
            return sub;
        }
    int splitArray(vector<int> &arr, int k)
    {
        int n = arr.size();
       	// Write your code here.
        if (n < k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int sub = find_sub(arr, n, mid);
            if (sub <= k)
            {

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
