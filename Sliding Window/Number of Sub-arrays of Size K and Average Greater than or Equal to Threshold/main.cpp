#include "numOfSubarrays.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<int> arr, int k, int threshold, int expected) {
    Solution sol;
    auto result = sol.numOfSubarrays(arr, k, threshold);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Standard case",
        {2,2,2,2,5,5,5,8}, 3, 4,
        3
    );

    // Test 2: first six subarrays qualify
    runTest("First six subarrays qualify",
        {11,13,17,23,29,31,7,5,2,3}, 3, 5,
        6
    );

    // Test 3: no subarray qualifies
    runTest("No subarray qualifies",
        {1,1,1,1,1}, 3, 5,
        0
    );

    // Test 4: all subarrays qualify
    runTest("All subarrays qualify",
        {10,10,10,10,10}, 2, 5,
        4
    );

    // Test 5: k equals array length
    runTest("K equals array length",
        {4,4,4}, 3, 4,
        1
    );

}
