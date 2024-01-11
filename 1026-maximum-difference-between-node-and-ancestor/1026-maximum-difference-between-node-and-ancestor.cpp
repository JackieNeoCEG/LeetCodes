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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return differ(root, root->val, root->val);
    }

//helper function to calculate largest difference
private:
    int differ(TreeNode* root, int minVal, int maxVal) {
        if (!root) {
            return maxVal - minVal;
        }
        
        //compares minimum and maximum values at each traversal
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        int leftDiff = differ(root->left, minVal, maxVal);
        int rightDiff = differ(root->right, minVal, maxVal);

        return max(leftDiff, rightDiff);
    }
};