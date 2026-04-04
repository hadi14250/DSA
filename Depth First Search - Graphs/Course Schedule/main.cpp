#include "courseSchedule.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, int numCourses, vector<vector<int>> prerequisites, bool expected) {
    Solution sol;
    auto result = sol.canFinish(numCourses, prerequisites);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case - no cycle
    runTest("Standard case - no cycle",
        2, {{1,0}},
        true
    );

    // Test 2: cycle - impossible
    runTest("Cycle - impossible",
        2, {{1,0},{0,1}},
        false
    );

    // Test 3: no prerequisites
    runTest("No prerequisites",
        3, {},
        true
    );

    // Test 4: longer chain with no cycle
    runTest("Longer chain no cycle",
        4, {{1,0},{2,1},{3,2}},
        true
    );

    // Test 5: cycle in larger graph
    runTest("Cycle in larger graph",
        4, {{1,0},{2,1},{3,2},{1,3}},
        false
    );

}
