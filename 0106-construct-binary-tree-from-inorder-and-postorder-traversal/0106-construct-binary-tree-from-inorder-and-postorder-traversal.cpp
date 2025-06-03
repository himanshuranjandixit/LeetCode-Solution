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
    TreeNode* solve(vector<int>&inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int,int>&mpp){
        if(instart>inend || poststart>postend) return NULL;
        TreeNode* node = new TreeNode(postorder[postend]);
        int index =mpp[postorder[postend]];
        int numleft=index-instart;
        node->left =solve(inorder,instart,index-1,postorder,poststart,poststart+numleft-1,mpp);
        node->right = solve(inorder,index+1,inend,postorder,poststart+numleft,postend-1,mpp);
        return node;

    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root = solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;

        
    }
};