/*
 * Problem #206: Reverse Linked List
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 8/17/2024, 12:57:46 PM
 * Link: https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;

            
        }
        return prev;
    }
};
