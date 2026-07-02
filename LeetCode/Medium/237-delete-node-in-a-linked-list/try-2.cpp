/*
 * Problem #237: Delete Node in a Linked List
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 12:12:43 AM
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
        ListNode* temp = node;
        while(temp->next){
            temp->val = temp->next->val;
            if(!temp->next->next) break;
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
        return;
    }
};
