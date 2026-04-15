/*
 * Problem #3885: Design Event Manager
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/31/2026, 7:31:38 PM
 * Link: https://leetcode.com/problems/design-event-manager/
 */

class EventManager {
public:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mpp;
    EventManager(vector<vector<int>>& events) {
        for(auto v : events){
            int id = v[0];
            int p = v[1];
            pq.push({p, -id});
            mpp[id] = p;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mpp[eventId] = newPriority;
        pq.push({newPriority,-eventId});
        
    }
    
    int pollHighest() {
        if(pq.empty()) return -1;
        int p,id;
        auto t = pq.top();
        pq.pop();
         p = t.first;
         id = -t.second;  
        if(mpp[id] == p){
            mpp.erase(id);
            return id;
        }
        while(!pq.empty() && mpp[id] != p){
            auto t = pq.top();
            pq.pop(); 
             p = t.first;
             id = -t.second;  
            if(mpp[id] == p){
                mpp.erase(id);
                return id;
            }
        }
        return -1;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
