/*
 * Problem #895: Maximum Frequency Stack
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2025, 6:08:59 PM
 * Link: https://leetcode.com/problems/maximum-frequency-stack/
 */

class FreqStack {
public:
    unordered_map<int, int> freq;
    typedef pair<int, pair<int, int>> ppi;// freq time el
    priority_queue<ppi> pq;
    
    int time = 0;
    FreqStack() {
    }
    
    void push(int val) {
        time++;
        freq[val]++;

        pq.push({freq[val], {time, val}});

    }
    
    int pop() {
          auto it = pq.top();
          pq.pop();
          int el = it.second.second;  
          freq[el]--;
          return el;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
