#include "productOfArrayExceptSelf.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<int> input, vector<int> expected) {
    Solution sol;
    auto result = sol.productExceptSelf(input);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    runTest("Standard case",
        {1,2,3,4},
        {24,12,8,6}
    );

    // Test 2: with zeros
    runTest("With zeros",
        {-1,1,0,-3,3},
        {0,0,9,0,0}
    );

    // Test 3: two elements
    runTest("Two elements",
        {2,3},
        {3,2}
    );

    // Test 4: with negative numbers
    runTest("Negative numbers",
        {-1,-2,-3,-4},
        {-24,-12,-8,-6}
    );

    // Test 5: with ones
    runTest("With ones",
        {1,1,1,1},
        {1,1,1,1}
    );

}
