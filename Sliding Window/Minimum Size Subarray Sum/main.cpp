#include "minSubArrayLen.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, int target, vector<int> nums, int expected) {
    Solution sol;
    auto result = sol.minSubArrayLen(target, nums);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Standard case",
        10, {2,1,5,1,5,3},
        3
    );

    // Test 2: no valid subarray
    runTest("No valid subarray",
        5, {1,2,1},
        0
    );

    // Test 3: single element equals target
    runTest("Single element equals target",
        4, {1,4,3},
        1
    );

    // Test 4: entire array needed
    runTest("Entire array needed",
        15, {1,2,3,4,5},
        5
    );

    // Test 5: first element exceeds target
    runTest("First element exceeds target",
        3, {10,2,3},
        1
    );

}
