class Twitter {
    int count;
    unordered_map<int, vector<pair<int, int>>> postMap;
    unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter(): count(0) {}
    
    void postTweet(int userId, int tweetId) {
        postMap[userId].push_back({count, tweetId});
        if(postMap[userId].size() > 10) postMap[userId].erase(postMap[userId].begin());
        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<int> res;

        if(followMap[userId].size() >= 10){
            priority_queue<vector<int>> maxHeap;
            for(auto f: followMap[userId]){
                if(postMap[f].size() > 0){
                    int idx = postMap[f].size()-1;
                    auto& p = postMap[f][idx];
                    maxHeap.push({-p.first, p.second, f, idx-1});
                    if(maxHeap.size() > 10) maxHeap.pop();
                }
            }

            while(!maxHeap.empty()){
                vector<int> top = maxHeap.top();
                maxHeap.pop();
                minHeap.push({-top[0], top[1], top[2], top[3]});
            }
        }else{
            for(auto f: followMap[userId]){
                if(!postMap.count(f)) continue;
                int idx = postMap[f].size() - 1;
                auto& p = postMap[f][idx];
                minHeap.push({p.first, p.second, f, idx-1});
            }
        }

        while(!minHeap.empty() && res.size() < 10){
            vector<int> top = minHeap.top();
            minHeap.pop();
            int idx = top[3];
            res.push_back(top[1]);
            if(idx >= 0){
                auto& p = postMap[top[2]][idx];
                minHeap.push({p.first, p.second, top[2], idx-1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)) followMap[followerId].erase(followeeId);
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