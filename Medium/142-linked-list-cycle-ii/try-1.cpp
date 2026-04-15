/*
 * Problem #142: Linked List Cycle II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/17/2024, 2:20:30 PM
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* detectCycle(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;
            while (fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
                if (slow == fast)
                {
                    slow = head;
                    while (slow != fast)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }
                    return slow;
                }
            }
            return NULL;
        }
};
