/*
 * Problem #146: LRU Cache
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/4/2026, 12:59:38 AM
 * Link: https://leetcode.com/problems/lru-cache/
 */

class LRUCache {
    class Node{
    public:
        int key,val;
        Node *prev,*next;

        Node(int key,int val){
            this->key = key;
            this->val = val;
            prev = next = nullptr;
        }
    };

public:
    int capacity;
    Node *head,*tail;
    unordered_map<int,Node*> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* n){
        Node* temp = head->next;

        n->next = temp;
        n->prev = head;

        head->next = n;
        temp->prev = n;
    }

    void deleteNode(Node* n){
        Node* p = n->prev;
        Node* q = n->next;

        p->next = q;
        q->prev = p;
    }

    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;

        Node* node = mpp[key];
        int ans = node->val;

        deleteNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            deleteNode(node);
            mpp.erase(key);
        }

        if(mpp.size()==capacity){
            Node* lru = tail->prev;
            mpp.erase(lru->key);
            deleteNode(lru);
        }

        Node* node = new Node(key,value);
        addNode(node);
        mpp[key] = node;
    }
};
