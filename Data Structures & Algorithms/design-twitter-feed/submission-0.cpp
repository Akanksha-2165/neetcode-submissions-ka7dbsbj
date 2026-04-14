class Twitter {
public:

    int time;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // max heap: {time, tweetId, userId, index}
        priority_queue<vector<int>> maxHeap;

        // user should follow themselves
        followMap[userId].insert(userId);

        for (int followee : followMap[userId]) {
            if (tweetMap.count(followee) && !tweetMap[followee].empty()) {
                int idx = tweetMap[followee].size() - 1;
                auto &tweet = tweetMap[followee][idx];

                maxHeap.push({tweet.first, tweet.second, followee, idx});
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int time = top[0];
            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            res.push_back(tweetId);

            if (idx > 0) {
                auto &nextTweet = tweetMap[user][idx - 1];
                maxHeap.push({nextTweet.first, nextTweet.second, user, idx - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};
