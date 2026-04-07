#include "containsDuplicate.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<int> nums, bool expected) {
    Solution sol;
    auto result = sol.hasDuplicate(nums);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: has duplicate
    runTest("Has duplicate",
        {1,2,3,3},
        true
    );

    // Test 2: no duplicates
    runTest("No duplicates",
        {1,2,3,4},
        false
    );

    // Test 3: single element
    runTest("Single element",
        {1},
        false
    );

    // Test 4: all same elements
    runTest("All same elements",
        {5,5,5,5},
        true
    );

    // Test 5: duplicate at start
    runTest("Duplicate at start",
        {2,2,3,4},
        true
    );

}
