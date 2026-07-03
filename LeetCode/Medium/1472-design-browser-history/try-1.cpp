/*
 * Problem #1472: Design Browser History
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2026, 12:43:39 AM
 * Link: https://leetcode.com/problems/design-browser-history/
 */

struct Node {
    string val;
    Node* prev;
    Node* next;

    Node(string x) {
        val = x;
        prev = nullptr;
        next = nullptr;
    }
};
     
class BrowserHistory {
public:
    // Node* dummyN = new Node("");
    Node* curr = NULL;
    BrowserHistory(string homepage) {
        Node* n =  new Node(homepage);
        curr = n;
        // dummyN->next = n;
        // n->prev = dummyN;

    }
    
    void visit(string url) {
        Node* n =  new Node(url);
        curr->next = n;
        n->prev = curr;
        curr = n;
    }
    
    string back(int steps) {
        while(curr->prev && steps--){
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next && steps--){
            curr = curr->next;
        }        
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
