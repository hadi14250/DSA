#include "lruCache.cpp"
#include <iostream>

using namespace std;

void runTest(string testName, bool passed) {
    if (passed) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case from problem example
    {
        LRUCache lru(2);
        lru.put(1, 10);
        lru.put(2, 20);
        lru.put(3, 30); // evicts key 1
        runTest("Standard case - evicted key returns -1",
            lru.get(2) == 20 && lru.get(1) == -1
        );
    }

    // Test 2: get updates recency - key 1 should survive eviction
    {
        LRUCache lru(2);
        lru.put(1, 10);
        lru.put(2, 20);
        lru.get(1);     // key 1 is now most recently used
        lru.put(3, 30); // evicts key 2, not key 1
        runTest("Get updates recency",
            lru.get(1) == 10 && lru.get(2) == -1
        );
    }

    // Test 3: put updates existing key value
    {
        LRUCache lru(2);
        lru.put(1, 10);
        lru.put(1, 99);
        runTest("Put updates existing key",
            lru.get(1) == 99
        );
    }

    // Test 4: capacity of 1
    {
        LRUCache lru(1);
        lru.put(1, 10);
        lru.put(2, 20); // evicts key 1
        runTest("Capacity of 1",
            lru.get(1) == -1 && lru.get(2) == 20
        );
    }

    // Test 5: get on missing key returns -1
    {
        LRUCache lru(2);
        runTest("Get on missing key",
            lru.get(42) == -1
        );
    }

}
