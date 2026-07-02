/*
 * Problem #19: Remove Nth Node From End of List
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 2:50:00 AM
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
        if(!head->next) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(n-- > 1){
            fast = fast->next;
        }
        if(fast->next == NULL){
            ListNode* t = head;
            head = head->next;
            delete(t);
            return head;
        }
        while(fast->next){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
         prev->next = slow->next;
        delete(slow);
        return head;
    }
};
