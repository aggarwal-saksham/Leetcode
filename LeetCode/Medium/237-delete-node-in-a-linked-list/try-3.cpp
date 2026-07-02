/*
 * Problem #237: Delete Node in a Linked List
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 12:14:17 AM
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next= node->next->next;
    }
};
