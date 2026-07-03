/*
 * Problem #206: Reverse Linked List
 * Difficulty: Easy
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 1:10:28 AM
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
        if(!head || !head->next) return head;
        ListNode* node = head;
        ListNode* back = NULL;
        while(node){
            ListNode* front = node->next;
            node->next = back;
            back = node;
            node = front;
        }
        return back;
    }
};
