/*
 * Problem #234: Palindrome Linked List
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 2:42:18 AM
 * Link: https://leetcode.com/problems/palindrome-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
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
    bool isPalindrome(ListNode* head) {
         ListNode *middle = middleNode(head);
        ListNode *secondHalf = reverseList(middle);
        ListNode *last = secondHalf;
        ListNode *first = head;
        while (first < middle)
        {
            if (first->val != last->val) return false;
            first = first->next;
            last = last->next;
        }
        return true;
    }
};
