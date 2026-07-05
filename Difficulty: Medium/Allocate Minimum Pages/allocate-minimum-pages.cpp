class Solution {
  public:
    bool possible(vector<int> &arr, int k, long long mid) {
        int students = 1;
        long long sum = 0;

        for (int x : arr) {
            if (sum + x > mid) {
                students++;
                sum = x;
            } else {
                sum += x;
            }
        }

        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        if (k > n) return -1;

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