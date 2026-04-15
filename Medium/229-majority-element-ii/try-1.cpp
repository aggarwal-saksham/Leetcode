/*
 * Problem #229: Majority Element II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/30/2024, 4:03:57 PM
 * Link: https://leetcode.com/problems/majority-element-ii/
 */

class Solution
{
    public:
        vector<int> majorityElement(vector<int> &v)
        {
            int n = v.size();	//size of the array

            int cnt1 = 0, cnt2 = 0;	// counts
            int el1 = INT_MIN;	// element 1
            int el2 = INT_MIN;	// element 2

           	// applying the Extended Boyer Moore's Voting Algorithm:
            for (int i = 0; i < n; i++)
            {
                if (cnt1 == 0 && el2 != v[i])
                {
                    cnt1 = 1;
                    el1 = v[i];
                }
                else if (cnt2 == 0 && el1 != v[i])
                {
                    cnt2 = 1;
                    el2 = v[i];
                }
                else if (v[i] == el1) cnt1++;
                else if (v[i] == el2) cnt2++;
                else
                {
                    cnt1--, cnt2--;
                }
            }
            vector<int> ls;	// list of answers

           	// Manually check if the stored elements in
           	// el1 and el2 are the majority elements:
            cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == el1) cnt1++;
                if (v[i] == el2) cnt2++;
            }

            int mini = int(n / 3) + 1;
            if (cnt1 >= mini) ls.push_back(el1);
            if (cnt2 >= mini) ls.push_back(el2);
            return ls;
        }
};
