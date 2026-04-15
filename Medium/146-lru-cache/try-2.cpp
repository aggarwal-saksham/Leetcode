/*
 * Problem #146: LRU Cache
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 2/4/2025, 4:00:06 PM
 * Link: https://leetcode.com/problems/lru-cache/
 */

class LRUCache
{
    public:
        class Node
        {
            public:
                int key;
            int val;
            Node * next;
            Node * prev;
            Node(int _key, int _val)
            {
                key = _key;
                val = _val;
            }
        };

    int cap;
    unordered_map<int, Node*> mpp;

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addAfterHead(Node *newN)
    {
        Node *next2head = head->next;
        head->next = newN;
        newN->next = next2head;
        newN->prev = head;
        next2head->prev = newN;
    }

    void deleteNode(Node *delNode)
    {
        Node *prev2del = delNode->prev;
        Node *next2del = delNode->next;
        prev2del->next = next2del;
        next2del->prev = prev2del;
    }
    int get(int key)
    {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node *ansNode = mpp[key];
        int ans = ansNode->val;

        deleteNode(ansNode);
        addAfterHead(ansNode);

        return ans;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *foundNode = mpp[key];
            foundNode->val = value;

            deleteNode(foundNode);
            addAfterHead(foundNode);

            mpp[key] = head->next;
            return;
            
        }

        if (mpp.size() == cap)	
        {
            Node *delNode = tail->prev;
            mpp.erase(delNode->key);
            deleteNode(delNode);
        }

        Node *newput = new Node(key, value);
        addAfterHead(newput);
        mpp[key] = newput;	
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */
