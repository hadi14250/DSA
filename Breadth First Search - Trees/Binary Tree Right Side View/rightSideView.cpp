#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> queue;
        TreeNode* rightSide = NULL;

        if(!root)
            return {};
        queue.push(root);

        while(queue.size() > 0) {
            int len = queue.size();
            for(int i = 0; i < len; i++) {
                TreeNode* node = queue.front();
                rightSide = node;
                queue.pop();
                if(node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            if(rightSide)
                res.push_back(rightSide->val);
        }
        return res;
    }
};
