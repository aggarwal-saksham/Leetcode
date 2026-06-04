/*
 * Problem #146: LRU Cache
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/4/2026, 12:40:53 AM
 * Link: https://leetcode.com/problems/lru-cache/
 */


class LRUCache {
class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};
public:
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->prev = tail;
        tail->next = head;
    }

    void addNode(Node* n){
        Node* prev2head = head->prev;
        prev2head->next = n;
        n->prev = prev2head;
        n->next = head;
        head->prev = n;
    }

    void deleteNode(Node* n){
        Node* prev2del = n->prev;
        Node* next2del = n->next;
        prev2del->next = next2del;
        next2del->prev = prev2del;
    }
    
    int get(int key) {
        int val = -1;
        if(mpp.find(key) != mpp.end()){
            Node* existing = mpp[key];
            val = existing->val;
            deleteNode(existing);
            mpp.erase(key);

            addNode(existing);
            mpp[key] = head->prev;
        }
        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* existing = mpp[key];
            deleteNode(existing);
            mpp.erase(key);
        }
        if(mpp.size() == capacity){
            mpp.erase(tail->next->key);
            deleteNode(tail->next);
        }
        addNode(new Node(key, value));
        mpp[key] = head->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
