/*
 * Problem #23: Merge k Sorted Lists
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/26/2025, 2:42:45 AM
 * Link: https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        typedef pair<int, ListNode*> pin;
        priority_queue<pin, vector<pin>, greater<pin>> minH;

        for(int i = 0; i < k; i++){
            ListNode* temp = lists[i];
            while(temp){
                minH.push({temp->val, temp});
                temp = temp->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!minH.empty()){
            temp->next = minH.top().second;
            temp = temp->next;
            minH.pop();
        }

        return dummy->next;
    }
};
