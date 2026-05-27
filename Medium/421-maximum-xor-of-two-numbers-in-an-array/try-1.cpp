/*
 * Problem #421: Maximum XOR of Two Numbers in an Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 1:25:27 AM
 * Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 */

struct Node{
    Node *links[2];

    bool containsKey(int bit){
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
    
};
class Solution {
public:
    Node* root = new Node();

    void insert(int num){
        Node *node = root;
        for(int i = 31; i>= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXOR(int num){
        Node* node = root;
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if(node->containsKey(1 - bit)){
                ans = ans | (1 << i);
                node = node->get(1 - bit);
            }
            else node = node->get(bit);
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums) {
            insert(num);
        }

        int res = 0;
        for(int num : nums){
            res = max(res, getMaxXOR(num));
        }
        return res;
    }
};
