/*
 * Problem #19: Remove Nth Node From End of List
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 8/31/2025, 9:06:26 PM
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(n){
            fast = fast->next;
            n--;            
        }
        if (fast == NULL)
            return head->next;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* node2del = slow->next;
        slow->next = node2del->next;
        delete node2del;    
        return head;   
    }
};
