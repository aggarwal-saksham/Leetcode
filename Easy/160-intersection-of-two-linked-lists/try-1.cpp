/*
 * Problem #160: Intersection of Two Linked Lists
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/19/2024, 8:44:48 PM
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
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        ListNode* temp = NULL;
        int lenA = 1, lenB = 1;
        while(tempA != NULL){
            tempA = tempA->next;
            lenA++;
        }
        while(tempB != NULL){
            tempB = tempB->next;
            lenB++;
        }
        int diff = abs(lenA - lenB);
        tempA = headA;
        tempB = headB;
        if(lenA >= lenB) {
            temp = headA;
            for(int i = 0; i < diff; i++)
                temp = temp->next;
            while(temp != tempB){
                temp = temp->next;
                tempB = tempB->next;

            }
            return temp;
            
        }
        else{
            temp = headB;
            for(int i = 0; i < diff; i++)
                temp = temp->next;
            while(temp != tempA){
                temp = temp->next;
                tempA = tempA->next;

            }
            return temp;
        }
        return NULL;

        
    }
};
