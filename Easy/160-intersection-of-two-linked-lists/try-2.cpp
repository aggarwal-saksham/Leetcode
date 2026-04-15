/*
 * Problem #160: Intersection of Two Linked Lists
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/19/2024, 10:55:32 PM
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
        {

            if (headA == NULL || headB == NULL) return NULL;
            ListNode *tempA = headA;
            ListNode *tempB = headB;
            while (tempA != tempB)
            {
                tempA = tempA->next;
                tempB = tempB->next;
                if (tempA == tempB) return tempA;
                if (tempA == NULL) tempA = headB;
                if (tempB == NULL) tempB = headA;
            }
            return tempA;
        }
};
