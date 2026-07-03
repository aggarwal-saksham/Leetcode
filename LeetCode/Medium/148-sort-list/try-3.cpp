/*
 * Problem #148: Sort List
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2026, 12:06:11 AM
 * Link: https://leetcode.com/problems/sort-list/
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        if (!head1 && !head2)
            return NULL;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } 
            else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if (head1)
            temp->next = head1;
        else
            temp->next = head2;

        return dummy->next;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* middle = middleNode(head);
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        ListNode* leftHead = head;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeTwoLists(leftHead, rightHead);
    }
};
