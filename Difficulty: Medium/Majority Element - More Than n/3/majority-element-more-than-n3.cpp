class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // code here
        //el1 :5 cnt : 2   el3 : 6  cnt2 : 0
        //5 5 3 2 5 5 6 5
        //1 2 1 2 1 3 3 2
        
       int n = arr.size();
       int el1 = 1e9, el2 = 1e9, cnt1 = 0, cnt2 = 0;
       for(int i = 0; i < n; i++){
           if(arr[i] == el1 || el1 == 1e9){
               el1 = arr[i];
               cnt1++;
           }
           else if(arr[i] == el2 || el2 == 1e9){
               el2 = arr[i];
               cnt2++;
           }
            else if(cnt1 == 0){
                el1 = arr[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                el2 = arr[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
}
       }
       cnt1 = 0, cnt2 = 0;
       for(int i = 0; i < arr.size(); i++){
           if(arr[i] == el1) cnt1++;
           else if(arr[i] == el2) cnt2++;
       }
       
       int mn = 1 + arr.size() / 3;
       vector<int> ans;
       if(cnt1 >= mn) ans.push_back(el1);
       if(cnt2 >= mn) ans.push_back(el2);
       sort(ans.begin(), ans.end());
       return ans;
       
         
        
    }
};