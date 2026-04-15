/*
 * Problem #410: Split Array Largest Sum
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/20/2024, 1:16:31 AM
 * Link: https://leetcode.com/problems/split-array-largest-sum/
 */

class Solution
{
    public:
        int find_stdnts(vector<int> &arr, int n, int pages)
        {
            int student = 1;
            long long pagesStudent = 0;
            for (int i = 0; i < n; i++)
            {
                if (pagesStudent + arr[i] <= pages)
                {
                    pagesStudent += arr[i];
                }
                else
                {
                    student++;
                    pagesStudent = arr[i];
                }
            }
            return student;
        }
    int splitArray(vector<int> &arr, int m)
    {
        int n = arr.size();
       	// Write your code here.
        if (n < m) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int student = find_stdnts(arr, n, mid);
            if (student <= m)
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
