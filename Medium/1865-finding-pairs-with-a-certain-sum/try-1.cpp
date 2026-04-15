/*
 * Problem #1865: Finding Pairs With a Certain Sum
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/6/2025, 1:38:31 PM
 * Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
 */

class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> mpp;
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for(int num : nums2){
            mpp[num]++;
        }
    }
    
    void add(int index, int val) {
        mpp[nums2[index]]--;
        nums2[index] += val;
        mpp[nums2[index]]++;

    }
    
    int count(int tot) {
        int cnt = 0;
        for(int num : nums1){
            cnt += mpp[tot - num];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
