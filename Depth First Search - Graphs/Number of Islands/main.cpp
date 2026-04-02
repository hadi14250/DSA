#include "numIslands.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, vector<vector<char>> grid, int expected) {
    Solution sol;
    auto result = sol.numIslands(grid);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: one large island
    runTest("One large island",
        {{'0','1','1','1','0'},
         {'0','1','0','1','0'},
         {'1','1','0','0','0'},
         {'0','0','0','0','0'}},
        1
    );

    // Test 2: four separate islands
    runTest("Four separate islands",
        {{'1','1','0','0','1'},
         {'1','1','0','0','1'},
         {'0','0','1','0','0'},
         {'0','0','0','1','1'}},
        4
    );

    // Test 3: all water
    runTest("All water",
        {{'0','0','0'},
         {'0','0','0'},
         {'0','0','0'}},
        0
    );

    // Test 4: all land
    runTest("All land - one island",
        {{'1','1','1'},
         {'1','1','1'},
         {'1','1','1'}},
        1
    );

    // Test 5: single cell islands
    runTest("Single cell islands",
        {{'1','0','1'},
         {'0','1','0'},
         {'1','0','1'}},
        5
    );

}
