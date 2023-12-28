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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {return result;}

        
    queue<TreeNode*> q;
    q.push(root); //enqueue

    while (!q.empty()) { //BFS
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) { //loop to process each node per level
            TreeNode* node = q.front(); //peek
            q.pop(); //dequeue front node
            currentLevel.push_back(node->val); //Adds the dequeued node value to currentLevel[]]
            //enqueues left/right if they exist for the next level
            if (node->left) {
                q.push(node->left); 
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        result.push_back(currentLevel); //appends the currentLevel vector to the result
    }

    return result;
    }
};