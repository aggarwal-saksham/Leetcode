/*
 * Problem #295: Find Median from Data Stream
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/29/2026, 3:10:47 PM
 * Link: https://leetcode.com/problems/find-median-from-data-stream/
 */

class MedianFinder {
public:
/*
{6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0}
6 out:6
6 10 out:8
2 6 10 out:6
2 6 6 10 out:6
2 5 6 6 10 out:6
0 2 5 6 6 10 out 5.5 
0 2 5 6 6 6 10 out 6 
0 2 3 5 6 6 6 10 out:5.5
0 1 2 3 5 6 6 6 10 out:5
0 0 1 2 3 5 6 6 6 10 out:5
0 0 0 1 2 3 5 6 6 6 10 out:5
*/
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;  

    MedianFinder() {}
    
    void addNum(int num) {
        if(maxH.empty() || num < maxH.top()) maxH.push(num);
        else minH.push(num);
        if(maxH.size() > minH.size() + 1){
            minH.push(maxH.top());
            maxH.pop();
        }
        if(maxH.size() < minH.size()){
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
