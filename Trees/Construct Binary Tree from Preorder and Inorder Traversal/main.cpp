#include "buildTree.cpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> treeToVector(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if(node) {
            res.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
    }
    return res;
}

void runTest(string testName, vector<int> preorder, vector<int> inorder, vector<int> expected) {
    Solution sol;
    TreeNode* result = sol.buildTree(preorder, inorder);
    if (treeToVector(result) == expected) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
}

int main() {
    // Test 1: standard case
    //     1
    //    / \
    //   2   3
    //        \
    //         4
    runTest("Standard case",
        {1,2,3,4}, {2,1,3,4},
        {1,2,3,4}
    );

    // Test 2: single node
    runTest("Single node",
        {1}, {1},
        {1}
    );

    // Test 3: left-skewed tree
    //     3
    //    /
    //   2
    //  /
    // 1
    runTest("Left-skewed tree",
        {3,2,1}, {1,2,3},
        {3,2,1}
    );

    // Test 4: right-skewed tree
    //   1
    //    \
    //     2
    //      \
    //       3
    runTest("Right-skewed tree",
        {1,2,3}, {1,2,3},
        {1,2,3}
    );

    // Test 5: balanced tree
    //       4
    //      / \
    //     2   6
    //    / \ / \
    //   1  3 5  7
    runTest("Balanced tree",
        {4,2,1,3,6,5,7}, {1,2,3,4,5,6,7},
        {4,2,6,1,3,5,7}
    );

}
