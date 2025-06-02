/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* node,vector<TreeNode*>& v){
        if(root==NULL) return false;
        v.push_back(root);
        if(root->val==node->val) return true;
        if(path(root->left,node,v) || path(root->right,node,v)) return true;
        v.pop_back();
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pvec;
        vector<TreeNode*>qvec;
        path(root,p,pvec);
        path(root,q,qvec);
        unordered_map<TreeNode*,int>mpp;
        for(auto it:pvec){
            mpp[it]=1;
        }
        for(int i=qvec.size()-1;i>=0;i--){
            if(mpp.find(qvec[i])!=mpp.end()) return qvec[i];
        }
        return NULL;
        
    }
};