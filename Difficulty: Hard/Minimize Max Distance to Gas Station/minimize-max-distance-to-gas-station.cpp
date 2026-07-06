class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        if(n == 1)return 0;

        vector<int> cnt(n - 1, 0);

        priority_queue<pair<double, int>> pq;

        for(int i = 1; i < n; i++){
            pq.push({(stations[i] - stations[i - 1]), i - 1});
        }

        while(k > 0){
            auto t = pq.top();
            pq.pop();

            auto[dist, idx] = t;

            cnt[idx]++;

            double og = stations[idx + 1] - stations[idx];
            double newD = og / (cnt[idx] + 1);

            pq.push({newD, idx});
            k--;
        }

        return pq.top().first;
    }
};