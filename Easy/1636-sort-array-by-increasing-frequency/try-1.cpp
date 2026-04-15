/*
 * Problem #1636: Sort Array by Increasing Frequency
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/23/2025, 2:37:58 PM
 * Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/
 */

class Solution
{
    public:

    typedef pair<int, int> pii;

    class comparator
    {
        public:
            bool operator()(pii a, pii b)
            {
                if (a.first != b.first) return a.first > b.first;

                else return a.second < b.second;
            }
    };

    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int num: nums)
        {
            mpp[num]++;
        }

        priority_queue<pii, vector <pii>, comparator> minH;

        for (auto i: mpp)
        {
            minH.push({ i.second,
                i.first });
        }

        vector<int> ans;

        while (!minH.empty())
        {
            int freq = minH.top().first;
            while (freq > 0)
            {
                ans.push_back(minH.top().second);
                freq--;
            }
            minH.pop();
        }

        return ans;
    }
};
