/*
 * Problem #981: Time Based Key-Value Store
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/9/2026, 1:05:40 AM
 * Link: https://leetcode.com/problems/time-based-key-value-store/
 */

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> kv;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        kv[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!kv.count(key)) return "";
        int idx = lower_bound(kv[key].begin(), kv[key].end(), make_pair(timestamp + 1, string())) - kv[key].begin();
        if(idx == 0) return "";
        return kv[key][idx - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
