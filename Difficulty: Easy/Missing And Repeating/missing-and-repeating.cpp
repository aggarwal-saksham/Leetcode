class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long asum = 0, nsum = 0, asqsum = 0, nsqsum = 0;
        int n = arr.size();

        nsum = (1LL * n * (n + 1)) / 2;
        nsqsum = (1LL * n * (n + 1) * (2 * n + 1)) / 6;

        for(int num : arr){
            asum += num;
            asqsum += 1LL * num * num;
        }

        long long eqn1 = asum - nsum;                         // x - y
        long long eqn2 = (asqsum - nsqsum) / eqn1;            // x + y

        long long rep = (eqn1 + eqn2) / 2;
        long long miss = rep - eqn1;

        
        return {(int)rep, (int)miss};
    }
};