class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
        
        int first =
            lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (first == nums.size() || nums[first] != target)
            return 0;
        int last =
            upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return last - first + 1;
    
    }
};
