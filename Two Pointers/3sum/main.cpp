#include "threeSum.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void runTest(string testName, vector<int> nums, vector<vector<int>> expected) {
    Solution sol;
    auto result = sol.threeSum(nums);
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
    runTest("Standard case",
        {-1,0,1,2,-1,-4},
        {{-1,-1,2},{-1,0,1}}
    );

    // Test 2: no valid triplets
    runTest("No valid triplets",
        {0,1,1},
        {}
    );

    // Test 3: all zeros
    runTest("All zeros",
        {0,0,0},
        {{0,0,0}}
    );

    // Test 4: all negatives
    runTest("All negatives",
        {-1,-2,-3,-4},
        {}
    );

    // Test 5: duplicates in input
    runTest("Duplicates in input",
        {-2,0,0,2,2},
        {{-2,0,2}}
    );

}
