#include "kthSmallest.cpp"
#include <iostream>

using namespace std;

void runTest(string testName, TreeNode* root, int k, int expected) {
    Solution sol;
    auto result = sol.kthSmallest(root, k);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case - k = 1
    //     2
    //    / \
    //   1   3
    runTest("Standard case k=1",
        new TreeNode(2, new TreeNode(1), new TreeNode(3)),
        1, 1
    );

    // Test 2: k = 4 in larger tree
    //       4
    //      / \
    //     3   5
    //    /
    //   2
    runTest("Larger tree k=4",
        new TreeNode(4,
            new TreeNode(3, new TreeNode(2), nullptr),
            new TreeNode(5)
        ),
        4, 5
    );

    // Test 3: single node
    runTest("Single node",
        new TreeNode(1),
        1, 1
    );

    // Test 4: k equals tree size
    //     3
    //    / \
    //   1   4
    //    \
    //     2
    runTest("K equals tree size",
        new TreeNode(3,
            new TreeNode(1, nullptr, new TreeNode(2)),
            new TreeNode(4)
        ),
        4, 4
    );

    // Test 5: right-skewed tree
    //   1
    //    \
    //     2
    //      \
    //       3
    runTest("Right-skewed tree k=2",
        new TreeNode(1, nullptr,
            new TreeNode(2, nullptr, new TreeNode(3))
        ),
        2, 2
    );

}
