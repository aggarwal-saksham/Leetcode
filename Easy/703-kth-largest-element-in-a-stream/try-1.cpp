/*
 * Problem #703: Kth Largest Element in a Stream
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/26/2025, 11:54:35 PM
 * Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */

class KthLargest
{
    public:
        priority_queue<int, vector < int>, greater < int>> minH;
    int x;
    KthLargest(int k, vector<int> &nums)
    {
        x = k;
        for (int num: nums)
        {
            minH.push(num);
            if (minH.size() > k)
            {
                minH.pop();
            }
        }
    }

    int add(int val)
    {
        minH.push(val);
        if (minH.size() > x)
        {
            minH.pop();
        }
        return minH.top();
    }
};

/**
 *Your KthLargest object will be instantiated and called as such:
 *KthLargest* obj = new KthLargest(k, nums);
 *int param_1 = obj->add(val);
 */
