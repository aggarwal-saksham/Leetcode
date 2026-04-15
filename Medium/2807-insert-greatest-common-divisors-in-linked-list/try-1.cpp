/*
 * Problem #2807: Insert Greatest Common Divisors in Linked List
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/11/2024, 1:11:52 AM
 * Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
 */

/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        int findGcd(int a, int b)
        {
           	// Continue loop as long as both
           	// a and b are greater than 0
            while (a > 0 && b > 0)
            {
               	// If a is greater than b,
               	// subtract b from a and update a
                if (a > b)
                {
                   	// Update a to the remainder
                   	// of a divided by b
                    a = a % b;
                }
               	// If b is greater than or equal
               	// to a, subtract a from b and update b
                else
                {
                   	// Update b to the remainder
                   	// of b divided by a
                    b = b % a;
                }
            }
           	// Check if a becomes 0,
           	// if so, return b as the GCD
            if (a == 0)
            {
                return b;
            }
           	// If a is not 0,
           	// return a as the GCD
            return a;
        }

    ListNode* insertGreatestCommonDivisors(ListNode *head)
    {
        if(head->next == NULL) return head;
        ListNode *temp1 = head;
        ListNode *temp2 = head->next;
        while (temp2 != NULL)
        {
            int x = findGcd(temp1->val, temp2->val);
            ListNode *newN = new ListNode(x);
            temp1->next = newN;
            newN->next = temp2;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return head;
    }
};
