#include "rottingOranges.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<vector<int>> grid, int expected) {
    Solution sol;
    auto result = sol.orangesRotting(grid);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case - all oranges rot in 4 minutes
    runTest("Standard case",
        {{2,1,1},
         {1,1,0},
         {0,1,1}},
        4
    );

    // Test 2: impossible - isolated fresh orange
    runTest("Impossible - isolated fresh orange",
        {{2,1,1},
         {0,1,1},
         {1,0,1}},
        -1
    );

    // Test 3: no fresh oranges
    runTest("No fresh oranges",
        {{0,2}},
        0
    );

    // Test 4: no rotten oranges but fresh exist
    runTest("No rotten oranges",
        {{1,1,1},
         {1,1,1}},
        -1
    );

    // Test 5: all empty
    runTest("All empty cells",
        {{0,0},
         {0,0}},
        0
    );

}
