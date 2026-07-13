class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        // 900 940 950 1100 1500 1800
        // 910 1120 1130 1200 1900 2000
        
        //arr[] = [935,1000, 1100],
        //dep[] = [1130, 1200, 1240, ]
        
        
        
        sort(arr.begin(), arr.end());//nlogn
        sort(dep.begin(), dep.end());//nlogn
        
        int l = 0;//for arr
        int r = 0; // for dep
        
        int platforms = 0;
        int cnt = 0;
        
        while(l < n && r < n){
            if(arr[l] <= dep[r]){
                cnt++;//3
                if(platforms < cnt){
                    platforms = cnt;//3
                }
                l++;
            }
            else{
                r++;
                cnt--;
            }
        }//n + n
        if(cnt > platforms) platforms = cnt;
        return platforms;
        
    }
};
