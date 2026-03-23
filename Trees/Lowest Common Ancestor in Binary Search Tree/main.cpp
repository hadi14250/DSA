#include "lowestCommonAncestor.cpp"
#include <iostream>

using namespace std;

void runTest(string testName, TreeNode* root, TreeNode* p, TreeNode* q, int expected) {
    Solution sol;
    TreeNode* result = sol.lowestCommonAncestor(root, p, q);
    if (result && result->val == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Build BST: [5,3,8,1,4,7,9,null,2]
    //         5
    //        / \
    //       3   8
    //      / \ / \
    //     1  4 7  9
    //      \
    //       2
    TreeNode* root = new TreeNode(5);
    root->left              = new TreeNode(3);
    root->right             = new TreeNode(8);
    root->left->left        = new TreeNode(1);
    root->left->right       = new TreeNode(4);
    root->right->left       = new TreeNode(7);
    root->right->right      = new TreeNode(9);
    root->left->left->right = new TreeNode(2);

    // Test 1: standard case - LCA of 3 and 8 is 5
    runTest("LCA of nodes on opposite sides",
        root, root->left, root->right, 5
    );

    // Test 2: node is ancestor of the other
    runTest("Node is ancestor of the other",
        root, root->left, root->left->right, 3
    );

    // Test 3: both nodes in right subtree
    runTest("Both nodes in right subtree",
        root, root->right->left, root->right->right, 8
    );

    // Test 4: both nodes in left subtree
    runTest("Both nodes in left subtree",
        root, root->left->left, root->left->right, 3
    );

    // Test 5: one node is root
    runTest("One node is root",
        root, root, root->right, 5
    );

}
