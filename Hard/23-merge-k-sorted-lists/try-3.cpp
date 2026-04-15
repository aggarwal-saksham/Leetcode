/*
 * Problem #23: Merge k Sorted Lists
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/26/2025, 2:54:58 AM
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

        for (int i = 0; i < k; i++) {
            ListNode* head = lists[i];
            if (head)
                minH.push({head->val, head});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!minH.empty()) {
            auto it = minH.top();
            minH.pop();

            if (it.second->next) {
                minH.push({it.second->next->val, it.second->next});
            }
            temp->next = it.second;
            temp = temp->next;
        }

        return dummy->next;
    }
};
