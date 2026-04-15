/*
 * Problem #234: Palindrome Linked List
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/18/2024, 1:04:29 PM
 * Link: https://leetcode.com/problems/palindrome-linked-list/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* middleNode(ListNode *head)
        {
            ListNode *fast = head;
            ListNode *slow = head;

            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    ListNode* reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *front = NULL;
        while (temp != NULL)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = middleNode(head);
        ListNode *secondHalf = reverseList(middle);
        ListNode *last = secondHalf;
        ListNode *first = head;
        while (last != NULL)
        {
            if (first->val != last->val) return false;
            first = first->next;
            last = last->next;
        }
        reverseList(secondHalf);
        return true;
    }
};
