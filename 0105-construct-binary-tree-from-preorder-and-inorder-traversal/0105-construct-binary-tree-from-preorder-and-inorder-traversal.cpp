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
    TreeNode* solve(vector<int>& preorder,int prestart, int preend, vector<int>& inorder,int instart, int inend,unordered_map<int,int>&mpp){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mpp[root->val];
        int numleft = inroot-instart;
        root->left = solve(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,mpp);
        root->right = solve(preorder,prestart+numleft+1,preend,inorder,inroot+1,inend,mpp);
        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root = solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
        
    }
};