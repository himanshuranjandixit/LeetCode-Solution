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
    void solve(TreeNode*root, TreeNode* node){
        if(root==NULL) return;
        if(root->val < node->val){
            if(root->right) solve(root->right,node);
            else{
                root->right=node;
                return;
            }
        }
        else{
            if(root->left) solve(root->left,node);
            else{
                root->left=node;
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root==NULL) return node;
        solve(root,node);
        return root;
        
    }
};