#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> dll;
    int _max_capacity;

public:
    LRUCache(int capacity): _max_capacity(capacity) {
        cache.clear();
    }

    int get(int key) {
        if(!cache.count(key))
            return -1;
        auto val = (*cache[key]).second;
        dll.erase(cache[key]);
        dll.push_front(make_pair(key, val));
        cache[key] = dll.begin();
        return(val);
    }

    void put(int key, int value) {
        if(cache.count(key)) {
            dll.erase(cache[key]);
            dll.push_front(make_pair(key,value));
            cache[key] = dll.begin();
            return ;
        }
        if (cache.size() >= (size_t)_max_capacity) {
            auto temp = --(dll.end());
            int oldKey = temp->first;
            dll.erase(temp);
            dll.push_front(make_pair(key,value));
            cache.erase(oldKey);
            cache[key] = dll.begin();
            return ;
        }
        dll.push_front(make_pair(key,value));
        cache[key] = dll.begin();
    }
};
