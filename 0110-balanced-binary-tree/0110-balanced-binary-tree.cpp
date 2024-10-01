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
    int maxdepth(TreeNode* root){
        if(root==NULL) return 0;
        int maxl=maxdepth(root->left);
        int maxr=maxdepth(root->right);
        if( maxl==-1 || maxr== -1 ||  abs(maxl-maxr)>1) return -1;
        return max(maxl,maxr)+1;

        
    } 
    bool isBalanced(TreeNode* root) {
        // int countl=0;
        // int countr=0;
        // TreeNode* templ = root;
        // TreeNode* tempr = root;
        // while(templ!=NULL){
        //     templ=templ->left;
        //     countl++;
        // }
        // while(tempr!=NULL){
        //     tempr=tempr->right;
        //     countr++;
        // }
        // int maxi=max(countl,countr);
        // int mini=min(countl,countr);
        // if(maxi-mini>1) return false;
        // return true;
        if(root==NULL) return true;
        if(maxdepth(root) == -1) return false;
        return true;
       
        
    }
};