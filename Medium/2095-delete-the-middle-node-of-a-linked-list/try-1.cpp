/*
 * Problem #2095: Delete the Middle Node of a Linked List
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/18/2024, 1:49:42 PM
 * Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* premiddleNode(ListNode *head)
        {
            ListNode *fast = head;
            ListNode *slow = head;
            fast = fast->next->next;

            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    ListNode* deleteMiddle(ListNode *head)
    {
            if(head->next == NULL) return NULL;
        ListNode *premiddle = premiddleNode(head);
        ListNode *middle = premiddle->next;
        premiddle->next = premiddle->next->next;
        middle->next = NULL;
        delete middle;
        return head;
    }
};
