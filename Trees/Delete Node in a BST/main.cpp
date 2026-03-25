#include "deleteNode.cpp"
#include <iostream>

using namespace std;

TreeNode* findNode(TreeNode* root, int val) {
    if(!root) return nullptr;
    if(root->val == val) return root;
    if(val < root->val) return findNode(root->left, val);
    return findNode(root->right, val);
}

bool isValidBST(TreeNode* root, long long min, long long max) {
    if(!root) return true;
    if(root->val <= min || root->val >= max) return false;
    return isValidBST(root->left, min, root->val) &&
           isValidBST(root->right, root->val, max);
}

// Build BST: [5,3,6,2,4,null,7]
//       5
//      / \
//     3   6
//    / \    \
//   2   4    7
TreeNode* buildTree() {
    TreeNode* root       = new TreeNode(5);
    root->left           = new TreeNode(3);
    root->right          = new TreeNode(6);
    root->left->left     = new TreeNode(2);
    root->left->right    = new TreeNode(4);
    root->right->right   = new TreeNode(7);
    return root;
}

void runTest(string testName, TreeNode* root, int key, bool expectNodeGone, bool expectValid) {
    Solution sol;
    root = sol.deleteNode(root, key);
    bool nodeGone = (findNode(root, key) == nullptr);
    bool valid = isValidBST(root, LLONG_MIN, LLONG_MAX);
    if (nodeGone == expectNodeGone && valid == expectValid) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: delete node with two children
    runTest("Delete node with two children",
        buildTree(), 3, true, true
    );

    // Test 2: delete key not in tree
    runTest("Delete key not in tree",
        buildTree(), 0, true, true
    );

    // Test 3: delete leaf node
    runTest("Delete leaf node",
        buildTree(), 2, true, true
    );

    // Test 4: delete root
    runTest("Delete root",
        buildTree(), 5, true, true
    );

    // Test 5: delete from empty tree
    Solution sol;
    TreeNode* result = sol.deleteNode(nullptr, 0);
    if (result == nullptr)
        cout << "[PASS] Delete from empty tree" << endl;
    else
        cout << "[FAIL] Delete from empty tree" << endl;

}
