/*
 * Problem #61: Rotate List
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2026, 11:12:14 PM
 * Link: https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* node = head;
        ListNode* front = head->next;
        int cnt = 1;
        while(temp->next){
            temp = temp->next;
            cnt++;
        }
        cout<<cnt;
        k = k % cnt;
        // if(k == 0) return head;
        temp->next = head;
        int rot = cnt - k - 1;
        while(rot--){
            node = node->next;
            front = node->next;
        }
        node->next = NULL;
        return front;
    }
};
