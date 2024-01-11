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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        return isMirror(root->left, root->right);
    }
    
private:
    bool isMirror(TreeNode* leftSub, TreeNode* rightSub) {
        // Both subtrees are empty, they are mirrors.
        if (!leftSub && !rightSub) {
            return true;
        }

        // One subtree is empty while the other is not, they are not mirrors.
        if (!leftSub || !rightSub) {
            return false;
        }

        // Check if their values match and recursively check the mirrored subtrees.
        bool valuesMatch = (leftSub->val == rightSub->val);
        bool outerMirror = isMirror(leftSub->left, rightSub->right);
        bool innerMirror = isMirror(leftSub->right, rightSub->left);

        // The tree is a mirror if both the values match and the subtrees are mirrored.
        return valuesMatch && outerMirror && innerMirror;
    }
};