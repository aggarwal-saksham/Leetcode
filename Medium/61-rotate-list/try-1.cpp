/*
 * Problem #61: Rotate List
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/19/2024, 12:50:32 AM
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

        if(!head) return NULL;
        if(!head->next) return head;
        if(k == 0) return head;
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next){
            temp = temp->next;
            cnt++;
        
        }
        ListNode* end = temp;
        ListNode* start = head;

        cout<<cnt;
        k = k % cnt;
        end->next = head;
        k = cnt - k;
        temp = head;
        for(int i = 1; i < k; i++){
            temp = temp->next;
        }
        start = temp->next;
        temp->next = nullptr;
        cout<<k;
        //cout<<temp->val;

    return start;
    }
};
