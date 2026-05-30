/*
 * Problem #355: Design Twitter
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/29/2026, 5:34:07 PM
 * Link: https://leetcode.com/problems/design-twitter/
 */

class Twitter {
public:
    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int clock = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({clock, tweetId});
        clock++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        vector<int> feed;
        for (int followee : following[userId]) {
            int i = tweets[followee].size() - 1;
            int cnt = 0;

            while (i >= 0 && cnt < 10) {
                pq.push(tweets[followee][i]);
                i--;
                cnt++;
            }
        }

        int i = tweets[userId].size() - 1;
        int cnt = 0;

        while (i >= 0 && cnt < 10) {
            pq.push(tweets[userId][i]);
            i--;
            cnt++;
        }
        while(!pq.empty() && feed.size() < 10){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId) != following[followerId].end()){
            following[followerId].erase(followeeId);
        }

    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
