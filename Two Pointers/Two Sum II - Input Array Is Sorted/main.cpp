#include "twoSumII.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<int> numbers, int target, vector<int> expected) {
    Solution sol;
    auto result = sol.twoSum(numbers, target);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Standard case",
        {2,7,11,15}, 9,
        {1,2}
    );

    // Test 2: non-adjacent elements
    runTest("Non-adjacent elements",
        {2,3,4}, 6,
        {1,3}
    );

    // Test 3: negative numbers
    runTest("Negative numbers",
        {-1,0}, -1,
        {1,2}
    );

    // Test 4: large array
    runTest("Large array",
        {1,2,3,4,5,6,7,8,9,10}, 19,
        {9,10}
    );

    // Test 5: same value elements
    runTest("Same value elements",
        {3,3}, 6,
        {1,2}
    );

}
