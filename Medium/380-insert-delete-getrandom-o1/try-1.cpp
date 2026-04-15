/*
 * Problem #380: Insert Delete GetRandom O(1)
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/15/2025, 3:06:43 AM
 * Link: https://leetcode.com/problems/insert-delete-getrandom-o1/
 */

class RandomizedSet {
public:
    unordered_map<int, int> mpp;
    vector<int> v;
    RandomizedSet() {}

    bool insert(int val) {
        if (mpp.find(val) == mpp.end()) {
            v.push_back(val);
            mpp[val] = v.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (mpp.find(val) != mpp.end()) {
            auto it = mpp.find(val);
            v[it->second] = v.back();
            v.pop_back();
            mpp[v[it->second]] = it->second;
            mpp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() { return v[rand() % v.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
