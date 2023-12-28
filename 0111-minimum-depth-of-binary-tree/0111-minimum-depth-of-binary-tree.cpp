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
    int minDepth(TreeNode* root) {
        if (root == NULL) {return 0;}
        TreeNode* L = root->left; TreeNode* R = root->right;
        if(L == NULL && R == NULL) {
            return 1;
        }

        if(L == NULL) {
            return 1 + minDepth(root->right);
        }

        if(R == NULL) {
            return 1 + minDepth(root->left);
        }

        return min(minDepth(L),minDepth(R)) + 1;
    }
};