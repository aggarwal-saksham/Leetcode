class Solution {
  public:
    bool possible(vector<int> &arr, int k, int mid){
        int n = arr.size();
        int mini = arr[0];
        k--;
        for(int i = 1; i < n; i++){
            if(arr[i] - mini > mid){
                k--;
                mini = arr[i];
            }
        }
        return (k <= 0);
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        
        int l = 1;
        int h = arr[n - 1] - arr[0];
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(possible(arr, k, mid)){
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return l;
    }
};