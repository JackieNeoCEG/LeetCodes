/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
       if (root == nullptr) {
            return 0;
        }

        int sum = 0;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();

            if (node != nullptr) {
                if (node->val > low) {
                    nodeStack.push(node->left);
                }
                if (node->val < high) {
                    nodeStack.push(node->right);
                }
                if (low <= node->val && node->val <= high) {
                    sum += node->val;
                }
            }
        }

        return sum;
    }
};