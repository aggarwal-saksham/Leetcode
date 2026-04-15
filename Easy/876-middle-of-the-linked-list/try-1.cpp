/*
 * Problem #876: Middle of the Linked List
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/16/2024, 4:57:49 PM
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* middleNode(ListNode *head)
        {
            int cnt = 1;
            ListNode *temp = head;
            if (head == NULL) return 0;
            while (temp->next != NULL)
            {
                temp = temp->next;
                cnt++;
            }
            int mid = (cnt / 2) + 1;
            temp = head;

            while (temp != NULL)
            {
                mid--;

                if (mid == 0) break;

                temp = temp->next;
            }
            return temp;
        }
};
