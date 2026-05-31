/*
 * Problem #135: Candy
 * Difficulty: Hard
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 5/31/2026, 6:09:08 PM
 * Link: https://leetcode.com/problems/candy/
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        //[100, 80, 70, 60, 70, 80, 90, 100, 90, 80, 70, 60, 60]
        // 1    3   6   10  12  15  19  24   25  27  30  34  35
        //[6, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 1, 0]
        //1   2  1  1  1  1  1  1  1  1  1  2  1
        //1   8  7  6  5  4  3  2  1  1  1  2  1
  
        int n = ratings.size();
            int ans = 1;
            int i = 1;
           	//int peak = 0, down = 0;
            while (i < n)
            {
                if (ratings[i] == ratings[i - 1])
                {
                    ans++;
                    i++;
                    continue;
                }

                int peak = 1;
                while (i < n && ratings[i] > ratings[i - 1])
                {
                    peak++;
                    ans += peak;
                    i++;
                
                }

                int down = 0;
                while (i < n && ratings[i] < ratings[i - 1])
                {
                    down++;
                    ans += down;
                    i++;
                
                }
                down++;

                if (down > peak)
                {
                    ans += down - peak;
                
                }

                
            }
            return ans;
    }
};
