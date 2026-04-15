/*
 * Problem #1482: Minimum Number of Days to Make m Bouquets
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/20/2024, 12:01:08 AM
 * Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 */

class Solution
{
    public:
        bool possible(vector<int> &bloomDay, int day, int m, int k)
        {
            int n = bloomDay.size();
            int cnt = 0;
            int bouquet = 0;
            for (int i = 0; i < n; i++)
            {
                if (bloomDay[i] <= day) cnt++;
                else
                {
                    bouquet += (cnt / k);
                    cnt = 0;
                }
            }
            bouquet += (cnt / k);
            if (bouquet >= m) return true;
            else return false;
        }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (((long long) m *(long long) k) > n) return -1;
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
         int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        
           
        
        int low = mini, high = maxi;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k))
            {
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return low;
    }
};
