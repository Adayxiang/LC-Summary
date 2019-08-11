##LRU Cache
```
1. Analysis
It is a typical design question. We need three data structures to store, shown below:
unordered_map<int,int> store; // key, value
list<int> KeyStore; // key
unordered_map<int, list<int>::iterator> Map;

Then we could record the relationship between key->value->pos;
We use list here in order to use O(1) time to erase and insert.


2. Time/Space Complexity:
Space: O(n)
Time: 
int get(int key): O(1)
void put(int key, int value): O(1)
LRUCache(int capacity): O(1)


3. Similar Problems:
460. LFU Cache
895. Maximum Frequency Stack
```