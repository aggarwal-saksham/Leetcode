/*
 * Problem #21: Merge Two Sorted Lists
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 7:33:18 PM
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
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        while(t1 && t2){
            if(t1->val < t2->val){
                temp->next = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }

            temp = temp->next;
        }

        while(t1){
            temp->next = t1;
            t1 = t1->next;
            temp = temp->next;
        }
        while(t2){
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
