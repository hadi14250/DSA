#include "rightSideView.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, TreeNode* root, vector<int> expected) {
    Solution sol;
    auto result = sol.rightSideView(root);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    //       1
    //      / \
    //     2   3
    //      \    \
    //       4    5
    runTest("Standard case",
        new TreeNode(1,
            new TreeNode(2, nullptr, new TreeNode(4)),
            new TreeNode(3, nullptr, new TreeNode(5))
        ),
        {1,3,5}
    );

    // Test 2: deep left subtree visible
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    //  /
    // 5
    runTest("Deep left subtree visible",
        new TreeNode(1,
            new TreeNode(2,
                new TreeNode(4, new TreeNode(5), nullptr),
                nullptr),
            new TreeNode(3)
        ),
        {1,3,4,5}
    );

    // Test 3: right-only child
    //   1
    //    \
    //     2
    runTest("Right-only child",
        new TreeNode(1, nullptr, new TreeNode(2)),
        {1,2}
    );

    // Test 4: empty tree
    runTest("Empty tree",
        nullptr,
        {}
    );

    // Test 5: single node
    runTest("Single node",
        new TreeNode(1),
        {1}
    );

}
