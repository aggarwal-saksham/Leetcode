class Solution {
  public:
    bool possible(vector<int> &arr, int k, long long mid) {
        int painters = 1;
        long long sum = 0;

        for (int x : arr) {
            if (sum + x > mid) {
                painters++;
                sum = x;
            } else {
                sum += x;
            }
        }

        return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();

        long long l = *max_element(arr.begin(), arr.end());
        long long h = accumulate(arr.begin(), arr.end(), 0LL);

        while (l <= h) {
            long long mid = l + (h - l) / 2;

            if (possible(arr, k, mid))
                h = mid - 1;
            else
                l = mid + 1;
        }

        return (int)l;
    }
};