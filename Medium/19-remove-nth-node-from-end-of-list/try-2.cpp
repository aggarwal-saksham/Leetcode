/*
 * Problem #19: Remove Nth Node From End of List
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/19/2024, 1:09:02 PM
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* front = NULL;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL)
            return head->next;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        front = slow->next;
        slow->next = front->next;
        delete front;
        return head;
    }
};
