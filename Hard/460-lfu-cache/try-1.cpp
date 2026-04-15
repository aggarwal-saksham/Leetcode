/*
 * Problem #460: LFU Cache
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2025, 1:32:54 AM
 * Link: https://leetcode.com/problems/lfu-cache/
 */

class LFUCache {
public:
    class Node {
    public:
        int key, val, freq;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            freq = 1;
        }
    };

    int cap;
    int minFreq;
    unordered_map<int, Node*> keyNode;              
    unordered_map<int, list<Node*>> freqList;       

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;

        list<Node*>& lst = freqList[freq];
        lst.remove(node);

        if (lst.empty()) {
            freqList.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        node->freq++;
        freqList[node->freq].push_front(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (keyNode.size() == cap) {
            list<Node*>& lst = freqList[minFreq];
            Node* nodeToRemove = lst.back();
            lst.pop_back();
            keyNode.erase(nodeToRemove->key);
            delete nodeToRemove;

            if (lst.empty()) {
                freqList.erase(minFreq);
            }
        }

        Node* newNode = new Node(key, value);
        keyNode[key] = newNode;
        freqList[1].push_front(newNode);
        minFreq = 1;
    }
};

