/*
 * Problem #21: Merge Two Sorted Lists
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 1/12/2026, 7:19:44 PM
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (!head1 && !head2)
            return NULL;
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(head1 && head2){
            if(head1->val < head2->val){
                temp->next = head1;
                head1 = head1->next;
            }
            else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        while(head1){
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;    
        }
        while(head2){
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;    
        }

        return dummy->next;
    }
};
