/*
 * Problem #141: Linked List Cycle
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 2:25:41 AM
 * Link: https://leetcode.com/problems/linked-list-cycle/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        bool hasCycle(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;
            while (fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast) return true;
            }
            return false;
        }
};
