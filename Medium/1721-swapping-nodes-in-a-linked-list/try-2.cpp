/*
 * Problem #1721: Swapping Nodes in a Linked List
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/13/2024, 10:17:35 PM
 * Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapNodes(ListNode *head, int k)
        {
            if (head->next == NULL) return head;
            ListNode *temp = head;
            ListNode *temp1 = head;
            ListNode *temp2 = head;
            int len = 0, cnt1 = 1, cnt2 = 1;
            while (temp != NULL)
            {
                temp = temp->next;
                len++;
            }
            while (cnt1 < k)
            {
                temp1 = temp1->next;
                cnt1++;
            }
            while (cnt2 < (len - k + 1))
            {
                temp2 = temp2->next;
                cnt2++;
            }

            int i = temp1->val;
            temp1->val = temp2->val;
            temp2->val = i;
            return head;
        }
};
