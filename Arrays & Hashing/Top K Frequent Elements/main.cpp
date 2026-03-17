#include "topKFrequentElements.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void runTest(string testName, vector<int> input, int k, vector<int> expected) {
    Solution sol;
    auto result = sol.topKFrequent(input, k);
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Multiple frequencies",
        {1,1,1,2,2,3}, 2,
        {1,2}
    );

    // Test 2: single element
    runTest("Single element",
        {1}, 1,
        {1}
    );

    // Test 3: longer array
    runTest("Longer array with ties",
        {1,2,1,2,1,2,3,1,3,2}, 2,
        {1,2}
    );

    // Test 4: all unique elements
    runTest("All unique, k=1",
        {1,2,3,4,5}, 1,
        {5}
    );

    // Test 5: all same element
    runTest("All same element",
        {4,4,4,4,4}, 1,
        {4}
    );

}
