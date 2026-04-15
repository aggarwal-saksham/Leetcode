/*
 * Problem #981: Time Based Key-Value Store
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/15/2025, 3:26:27 PM
 * Link: https://leetcode.com/problems/time-based-key-value-store/
 */

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = mpp.find(key);
        if (it == mpp.end()) {
            return "";
        }
        auto& v = it->second;
        int n = v.size();
        int l = 0, h = n - 1, ans = -1;
        while (l <= h) {
            int m = l - (l - h) / 2;
            if (v[m].first == timestamp)
                return v[m].second;
            if (v[m].first < timestamp) {
                ans = m;
                l = m + 1;
            } else
                h = m - 1;
        }
        if (ans == -1)
            return "";
        return v[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
