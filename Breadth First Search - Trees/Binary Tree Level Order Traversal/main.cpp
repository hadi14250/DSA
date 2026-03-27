#include "levelOrder.cpp"
#include <iostream>
#include <vector>

using namespace std;

void runTest(string testName, TreeNode* root, vector<vector<int>> expected) {
    Solution sol;
    auto result = sol.levelOrder(root);
    if (result == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case - full binary tree
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    TreeNode* root1 = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), new TreeNode(7))
    );
    runTest("Standard case",
        root1,
        {{1},{2,3},{4,5,6,7}}
    );

    // Test 2: single node
    runTest("Single node",
        new TreeNode(1),
        {{1}}
    );

    // Test 3: empty tree
    runTest("Empty tree",
        nullptr,
        {}
    );

    // Test 4: left-skewed tree
    //     1
    //    /
    //   2
    //  /
    // 3
    runTest("Left-skewed tree",
        new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr),
        {{1},{2},{3}}
    );

    // Test 5: two levels
    //     1
    //    / \
    //   2   3
    runTest("Two levels",
        new TreeNode(1, new TreeNode(2), new TreeNode(3)),
        {{1},{2,3}}
    );

}
