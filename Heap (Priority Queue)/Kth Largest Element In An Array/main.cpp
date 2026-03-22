#include "findKthLargest.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<int> nums, int k, int expected) {
    Solution sol;
    auto result = sol.findKthLargest(nums, k);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Standard case",
        {3,2,1,5,6,4}, 2,
        5
    );

    // Test 2: duplicates in array
    runTest("Duplicates in array",
        {3,2,3,1,2,4,5,5,6}, 4,
        4
    );

    // Test 3: k equals array size
    runTest("K equals array size",
        {1,2,3,4,5}, 5,
        1
    );

    // Test 4: k equals 1
    runTest("K equals 1",
        {7,3,9,1,5}, 1,
        9
    );

    // Test 5: single element
    runTest("Single element",
        {42}, 1,
        42
    );

}
