class LRUCache {
public:
    int capacity;
    vector<pair<int, int>> lru;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i < lru.size(); i++){
            if(lru[i].first == key){
                auto tmp = lru[i];
                lru.erase(lru.begin()+i);
                lru.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < lru.size(); i++){
            if(lru[i].first == key) lru.erase(lru.begin()+i);
        }
        lru.push_back({key, value});
        if(lru.size() > capacity) lru.erase(lru.begin());
    }
};
