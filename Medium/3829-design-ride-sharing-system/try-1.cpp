/*
 * Problem #3829: Design Ride Sharing System
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/4/2026, 7:38:00 PM
 * Link: https://leetcode.com/problems/design-ride-sharing-system/
 */

class RideSharingSystem {
public:
queue<int> riders;
queue<int> drivers;
set<int> s;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        s.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!riders.empty() && s.find(riders.front()) == s.end()){
            riders.pop();
        }
        if(!riders.empty() && !drivers.empty()){
            int r = riders.front();
            riders.pop();
            int d = drivers.front();
            drivers.pop();
            return {d, r};
        }
        else return {-1, -1};
    }
    
    void cancelRider(int riderId) {
        s.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
