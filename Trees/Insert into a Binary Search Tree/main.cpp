#include "insertIntoBST.cpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

TreeNode* buildBST(vector<int> vals) {
    if(vals.empty()) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    for(size_t i = 1; i < vals.size(); i++) {
        Solution sol;
        root = sol.insertIntoBST(root, vals[i]);
    }
    return root;
}

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

void runTest(string testName, vector<int> input, int val, int expectedSize) {
    Solution sol;
    TreeNode* root = buildBST(input);
    root = sol.insertIntoBST(root, val);
    TreeNode* inserted = findNode(root, val);
    bool valid = isValidBST(root, LLONG_MIN, LLONG_MAX);
    if (inserted && valid) {
        cout << "[PASS] " << testName << endl;
    } else {
        cout << "[FAIL] " << testName << endl;
    }
    (void)expectedSize;
}

int main() {
    // Test 1: standard case - insert 6 into [5,3,9,1,4]
    runTest("Standard case",
        {5,3,9,1,4}, 6, 6
    );

    // Test 2: insert into larger tree
    runTest("Larger tree",
        {5,3,6,4,10,7}, 9, 7
    );

    // Test 3: insert into empty tree
    Solution sol;
    TreeNode* result = sol.insertIntoBST(nullptr, 42);
    if (result && result->val == 42)
        cout << "[PASS] Insert into empty tree" << endl;
    else
        cout << "[FAIL] Insert into empty tree" << endl;

    // Test 4: insert smaller than all nodes
    runTest("Insert smallest value",
        {5,3,9,1,4}, -5, 6
    );

    // Test 5: insert larger than all nodes
    runTest("Insert largest value",
        {5,3,9,1,4}, 100, 6
    );

}
