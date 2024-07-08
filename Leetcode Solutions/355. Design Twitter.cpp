class Twitter {
public:
    unordered_map<int, unordered_set<int>>_follow;
    unordered_map<int, deque<pair<int,int>>>_tweet;
    int timestamp;
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(_tweet[userId].size() > 10) _tweet[userId].pop_front();
        _tweet[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(auto it : _tweet[userId]){
            pq.push({it.first, it.second});
            if(pq.size() > 10) pq.pop();
        }
        
        for(auto user_id : _follow[userId]){
            for(auto tweet : _tweet[user_id]){
                pq.push({tweet.first, tweet.second});
                if(pq.size() > 10) pq.pop();
            }
        }
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        _follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = _follow[followerId].find(followeeId);
        _follow[followerId].erase(followeeId);
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