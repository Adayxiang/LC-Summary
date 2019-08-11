class LRUCache {
private:
    unordered_map<int,int> store; // key, value
    list<int> KeyStore; // key
    unordered_map<int, list<int>::iterator> Map;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(store.count(key))
        {
            auto cur = Map[key];
            KeyStore.erase(cur);
            KeyStore.push_back(key);
            Map[key] = prev(KeyStore.end());
            return store[key];
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(store.count(key))
        {
            auto cur = Map[key];
            KeyStore.erase(cur);
            KeyStore.push_back(key);
            Map[key] = prev(KeyStore.end());
            store[key] = value;
        }
        else
        {
            if(cap != 0)
            {
                KeyStore.push_back(key);
                Map[key] = prev(KeyStore.end());
                store[key] = value;
                --cap;
            }
            else
            {
                auto cur = KeyStore.front();
                KeyStore.pop_front();
                store.erase(cur);
                Map.erase(cur);
                KeyStore.push_back(key);
                Map[key] = prev(KeyStore.end());
                store[key] = value;
            }
        }
    }
};