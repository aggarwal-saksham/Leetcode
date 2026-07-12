class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        // code here
        vector<pair<int, int>> meetings;
        for (int i = 0; i < start.size(); i++) {
            meetings.push_back({end[i], start[i]}); 
           
        }

        sort(meetings.begin(), meetings.end());
        int cnt = 0;
        int last = -1;
        for(auto &m : meetings){
            auto[e, s] = m;
            
            if(s > last){
                cnt++;
                
                last = e;
            }
            
        }
        return cnt;
        
    }
};