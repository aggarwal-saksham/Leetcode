/*
 * Problem #1707: Maximum XOR With an Element From Array
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 1:36:44 PM
 * Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
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

    

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> copy;
        
        for(int i = 0; i < queries.size(); i++){
            copy.push_back({queries[i][1], i, queries[i][0]});
        }

        sort(copy.begin(), copy.end());
        sort(nums.begin(), nums.end());
        int l = 0;
        int n = nums.size();
        vector<int> ans(queries.size());
        for(auto q : copy){
            int m = q[0];
            int og = q[1];
            int x = q[2];

            while(l < n && nums[l] <= m){
                insert(nums[l]);
                l++;
            } 

            if(l == 0){
                ans[og] = -1;
            }
            else{
                ans[og] = getMaxXOR(x);
            }
        }


        return ans;
    }
};
