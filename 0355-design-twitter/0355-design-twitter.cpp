class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;

public:
    Twitter() : timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        unordered_set<int> users = followees[userId];
        users.insert(userId);

        for (int u : users) {
            auto it = tweets.find(u);
            if (it == tweets.end()) continue;

            const auto& userTweets = it->second;
            int count = 0;
            for (int i = (int)userTweets.size() - 1; i >= 0 && count < 10; --i, ++count) {
                minHeap.push(userTweets[i]);
                if (minHeap.size() > 10) {
                    minHeap.pop();
                }
            }
        }

        vector<int> feed(minHeap.size());
        for (int i = (int)feed.size() - 1; i >= 0; --i) {
            feed[i] = minHeap.top().second;
            minHeap.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};