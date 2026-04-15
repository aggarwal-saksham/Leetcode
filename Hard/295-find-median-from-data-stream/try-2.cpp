/*
 * Problem #295: Find Median from Data Stream
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/5/2025, 5:35:22 PM
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 */

class MedianFinder {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;  
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (maxH.empty() && minH.empty()) {
            maxH.push(num);
        } else if (maxH.empty() || minH.empty()) {
            if (num < maxH.top()) {
                minH.push(maxH.top());
                maxH.pop();
                maxH.push(num);
            } else {
                minH.push(num);
            }
        } else if (num < maxH.top() && num < minH.top()) {
            maxH.push(num);
            if ((maxH.size() - minH.size()) > 1) {
                minH.push(maxH.top());
                maxH.pop();
            }
        } else if (num > maxH.top() && num > minH.top()) {
            minH.push(num);
            if ((minH.size() - maxH.size()) > 0) {
                maxH.push(minH.top());
                minH.pop();
            }
        } else {
            if ((maxH.size() - minH.size()) <= 0) {
                maxH.push(num);
            } else {
                minH.push(num);
            }
        }
    }
    
    double findMedian() {
        if((minH.size() + maxH.size()) % 2 != 0){
            return (double)maxH.top();
        }
        return (double)(minH.top() + maxH.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
