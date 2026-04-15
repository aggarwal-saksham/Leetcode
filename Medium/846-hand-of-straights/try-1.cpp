/*
 * Problem #846: Hand of Straights
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/24/2025, 1:54:05 PM
 * Link: https://leetcode.com/problems/hand-of-straights/
 */

class Solution
{
    public:
        bool isNStraightHand(vector<int> &hand, int groupSize)
        {
            if (hand.size() % groupSize != 0) return false;
            sort(hand.begin(), hand.end());

            unordered_map<int, int> mpp;

            for (int card: hand)
            {
                mpp[card]++;
            }

            for (int card: hand)
            {
                if (mpp[card] == 0) continue;

                for (int i = 0; i < groupSize; i++)
                {
                    if (mpp[card + i] <= 0) return false;
                    else mpp[card + i]--;
                }
            }

            return true;
        }
};
