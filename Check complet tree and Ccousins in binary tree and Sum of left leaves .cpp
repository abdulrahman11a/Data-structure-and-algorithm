#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <numeric> // std::accumulate
#include <cassert>
#include <string>

using namespace std;


// *****************        Check Completeness of a Binary Tree   p6  ******************//


/**
 #include <queue>
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

/*
class Solution {
public:
    bool is_leaf_node(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    bool is_perfect(TreeNode* node) {
        if (!node) return false; // A null node cannot be perfect
        if (is_leaf_node(node)) return true; // Leaf node is considered perfect
        if (node->left != nullptr && node->right != nullptr) return true; // Node with two children is perfect
        return false; // Node with only one child is not perfect
    }

    bool isCompleteTree(TreeNode* root) {
        if (!root) return true; // An empty tree is complete

        std::queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false; // Flag to indicate if a null node was found

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                if (foundNull) return false; // If a null node was found before and now a non-null node is found, the tree is incomplete
                
                q.push(current->left);
                q.push(current->right);
            } else {
                foundNull = true; // Mark that we have encountered a null node
            }
        }

        return true; // If we traversed all nodes without inconsistencies, the tree is complete
    }
};


*/

//// *****************        CCousins in Binary Tree p5  ******************////

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
/**
 
class Solution {
public:
    // Function to get the depth of a node
    int get_the_Depth(TreeNode* root, int val, int coun = 0) {
        if (!root) return -1; // Base case: if root is null, return -1 indicating not found

        if (root->val == val) return coun; // If the current node's value matches val, return the current depth

        int leftDepth = get_the_Depth(root->left, val, coun + 1);
        if (leftDepth != -1) return leftDepth; // If found in the left subtree, return the depth

        // Recursively search in the right subtree
        return get_the_Depth(root->right, val, coun + 1); // Return the depth found in the right subtree
    }

    // Function to get the parent value of a node
    int get_the_parent(TreeNode* root, int prev_nod, int b1) {
        if (!root) return -1; // Base case: if root is null, return -1 indicating not found

        if (root->val == b1) return prev_nod; // If current node matches b1, return the parent value

        // Search in the left subtree
        int leftParent = get_the_parent(root->left, root->val, b1);
        if (leftParent != -1) return leftParent; // If found in left subtree, return the parent value

        // Search in the right subtree
        return get_the_parent(root->right, root->val, b1); // Return the parent value found in the right subtree
    }

    // Function to check if two nodes are cousins
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false; // If the root is null, they can't be cousins

        // Get depths of both nodes
        int depthX = get_the_Depth(root, x);
        int depthY = get_the_Depth(root, y);

        // Get parents of both nodes
        int parentX = get_the_parent(root, -1, x); // Initial parent as -1 (indicating no parent)
        int parentY = get_the_parent(root, -1, y);

        // Check if they have the same depth but different parents
        return (depthX == depthY) && (parentX != parentY);
    }
};
*/

////// *****************       . Sum of Left Leaves p4 ******************////


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

/*
class Solution {
public:
    // Helper function to calculate the sum of left leaves
    int _sumOfLeftLeaves(TreeNode* root, bool isLeft) {
        // Base case: if the node is null, return 0
        if (!root) return 0;

        // If the node is a leaf and it's a left child, return its value
        if (!root->left && !root->right && isLeft) return root->val;

        // Recur for left and right subtrees
        int leftSum = _sumOfLeftLeaves(root->left, true);
        int rightSum = _sumOfLeftLeaves(root->right, false);

        // Return the sum of left leaves
        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return _sumOfLeftLeaves(root, false);  // Start with the root, which is not a left child
    }
};

*/
