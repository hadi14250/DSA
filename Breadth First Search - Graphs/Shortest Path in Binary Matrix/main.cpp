#include "shortestPathBinaryMatrix.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<vector<int>> grid, int expected) {
    Solution sol;
    auto result = sol.shortestPathBinaryMatrix(grid);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case - path of length 3
    runTest("Standard case",
        {{0,1,0},
         {1,0,0},
         {1,1,0}},
        3
    );

    // Test 2: blocked start - no path
    runTest("Blocked start",
        {{1,0},
         {1,1}},
        -1
    );

    // Test 3: single cell clear
    runTest("Single clear cell",
        {{0}},
        1
    );

    // Test 4: single cell blocked
    runTest("Single blocked cell",
        {{1}},
        -1
    );

    // Test 5: clear diagonal path
    runTest("Clear diagonal path",
        {{0,0,0},
         {0,0,0},
         {0,0,0}},
        3
    );

}
