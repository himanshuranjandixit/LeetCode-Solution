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
    int cnt(TreeNode* root){
        if(!root) return 0;
        return 1 + cnt(root->left) + cnt(root->right);
    }
    bool dfs(TreeNode* root,int t,int i){
        if(!root) return true;
        if(i>t) return false;
        return dfs(root->left,t,2*i) & dfs(root->right,t,2*i+1);
    }
    bool isCompleteTree(TreeNode* root) {
       int t = cnt(root);
       int i=1;
       return dfs(root,t,i);
        
    }
};