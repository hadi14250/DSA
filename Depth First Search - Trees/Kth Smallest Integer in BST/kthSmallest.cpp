#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int val;
        if(root)
            val = root->val;

        inorder(root, k, i, val);
        return val;
    }

    void inorder(TreeNode* root, int k, int& i, int& val) {
        if(!root)
            return ;
        inorder(root->left, k, i, val);
        i++;
        if(k == i) {
            val = root->val;
            return ;
        }
        inorder(root->right, k, i, val);
    }
};
