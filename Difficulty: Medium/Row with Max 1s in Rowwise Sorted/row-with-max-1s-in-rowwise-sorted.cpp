class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m= arr[0].size();
        int ans = -1;
        int maxi = 0;
        
        for(int i = 0; i < n; i++){
            
            int it = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
            int ones = m - it;
            if(ones > maxi){
                maxi = ones;
                ans = i;
            }
        }
        return ans;
    }
    
};