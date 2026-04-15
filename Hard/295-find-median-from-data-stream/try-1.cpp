/*
 * Problem #295: Find Median from Data Stream
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/26/2025, 1:06:08 AM
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 */

class MedianFinder {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;  
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxH.empty() || num <= maxH.top()){
            maxH.push(num);
        } else {
            minH.push(num);
        }
        
        if(maxH.size() > minH.size() + 1){
            minH.push(maxH.top());
            maxH.pop();
        } else if(minH.size() > maxH.size()){
            maxH.push(minH.top());
            minH.pop();
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
