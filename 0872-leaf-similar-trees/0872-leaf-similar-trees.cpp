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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeafSequence(root1, leaves1); 
        getLeafSequence(root2, leaves2);

        return (leaves1 == leaves2); //returns boolean statement
    }

//encapsulate a helper function
private:
    void getLeafSequence(TreeNode* root, vector<int>& leaves) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) { //reached the leaf
            leaves.push_back(root->val); //append to vector
        }
        
        //recursive approach for Depth first search
        getLeafSequence(root->left, leaves);
        getLeafSequence(root->right, leaves);
    }
};