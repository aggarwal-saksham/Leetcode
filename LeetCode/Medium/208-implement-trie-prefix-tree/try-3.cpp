/*
 * Problem #208: Implement Trie (Prefix Tree)
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/22/2026, 12:56:12 AM
 * Link: https://leetcode.com/problems/implement-trie-prefix-tree/
 */

struct Node{
    Node *links[26];
    bool ends = false;

    bool containsKey(char c){
        return links[c - 'a'] != nullptr;
    }

    void put(char c, Node* node){
        links[c - 'a'] = node;
    }
    Node* getNode(char c){
        return links[c- 'a'];
    }
    void setEnd(){
        ends = true;
    }
    bool isEnd() {
        return ends;
    }    
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node()); 
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++){
            if(!node->containsKey(word[i])) return false;
            else node = node->getNode(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++){
            if(!node->containsKey(word[i])) return false;
            else node = node->getNode(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
