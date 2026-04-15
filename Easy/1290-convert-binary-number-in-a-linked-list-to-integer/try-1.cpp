/*
 * Problem #1290: Convert Binary Number in a Linked List to Integer
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/14/2025, 12:54:04 PM
 * Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int countLen(ListNode* head){
        int len = 1;
        while(head->next){
            head = head->next;
            len++;
        }

        return len;
    }
    int getDecimalValue(ListNode* head) {
        int n = countLen(head);
        int wt = pow(2, n - 1);

        int ans = 0;

        while(head){
            if(head->val == 1){
                ans += wt;
            
            }
            head = head->next;
            wt /= 2;
        }

        return ans;
    }
};
