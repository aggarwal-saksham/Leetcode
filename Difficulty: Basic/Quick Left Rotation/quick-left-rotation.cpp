class Solution {

  public:
    void leftRotate(vector<int>& arr, int k) {
        // Your code goes here
        int n = arr.size();
        k %= n;
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + n - k);
        reverse(arr.begin() + n - k, arr.end());
    }
};