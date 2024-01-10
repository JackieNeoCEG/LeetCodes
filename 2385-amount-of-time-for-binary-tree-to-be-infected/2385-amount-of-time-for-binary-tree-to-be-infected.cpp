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
    int amountOfTime(TreeNode* root, int start) {
        int minute = 0;
        unordered_map<int, unordered_set<int>> adjList;
        convert(root, adjList); //start at root
        queue<int> q;
        q.push(start);
        unordered_set<int> visited; //set to keep track of visited nodes
        visited.insert(start);
        
        //BFS using queue, iterates over each level
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize > 0) {
                int current = q.front();
                q.pop();

                for (int num : adjList[current]) {
                    if (visited.find(num) == visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute - 1;
    }
    
    //adjacency list where key: node's value, value: unordered_set of parent and children nodes' values
    void convert(TreeNode* currentNode, unordered_map<int, unordered_set<int>>& adjList) {
        if (currentNode == nullptr) {
            return;
        }

        // Initialize the set for the current node
        adjList[currentNode->val]; 

        if (currentNode->left != nullptr) {
            adjList[currentNode->val].insert(currentNode->left->val);
            adjList[currentNode->left->val].insert(currentNode->val);  // Ensure bidirectional connection
            convert(currentNode->left, adjList);
        }

        if (currentNode->right != nullptr) {
            adjList[currentNode->val].insert(currentNode->right->val);
            adjList[currentNode->right->val].insert(currentNode->val);  // Ensure bidirectional connection
            convert(currentNode->right, adjList);
        }
    }
};