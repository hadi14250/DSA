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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> queue;

        if(!root)
            return {};

        queue.push(root);
        int level = 0;
        while(queue.size() > 0) {
            res.push_back({});
            int len = queue.size();
            for(int i = 0; i < len; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                res[level].push_back(node->val);

                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
            level++;
        }
        return res;
    }
};
