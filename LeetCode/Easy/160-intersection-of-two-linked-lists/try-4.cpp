/*
 * Problem #160: Intersection of Two Linked Lists
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/27/2026, 5:29:55 PM
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1->next && t2->next){
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t2->next){
            t2 = t2->next;
            headB = headB->next;
        }
        while(t1->next){
            t1 = t1->next;
            headA = headA->next;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
