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
    TreeNode* bstToGst(TreeNode* root) {



        //  EDITORIAL SOLUTION ---->>>>

        // *****************************************************************************************
        // *****************************************************************************************


      
        // Store the inorder traversal in an array.
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);

        // Reverse the array to get descending order.
        reverse(inorderTraversal.begin(), inorderTraversal.end());

        // Modify the values in the tree.
        replaceValues(root, inorderTraversal);

        return root;
    }

private:
    // Perform any traversal of your choice to store node values.
    void inorder(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    // Function to modify the values in the tree.
    void replaceValues(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        replaceValues(root->left, inorderTraversal);
        replaceValues(root->right, inorderTraversal);

        int nodeSum = 0;
        // Replace node with values greater than the current value.
        for (auto i : inorderTraversal) {
            if (i > root->val) {
                nodeSum += i;
            } else {
                break;
            }
        }

        root->val += nodeSum;
    }
        
    
};