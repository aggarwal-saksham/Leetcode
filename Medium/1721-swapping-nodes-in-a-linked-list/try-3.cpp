/*
 * Problem #1721: Swapping Nodes in a Linked List
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2025, 8:43:51 PM
 * Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < k - 1; i++) {
            fast = fast->next;
        }

        ListNode* kFromBegin = fast;

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* kFromEnd = slow;

        int temp = kFromBegin->val;
        kFromBegin->val = kFromEnd->val;
        kFromEnd->val = temp;

        return head;
    }
};
