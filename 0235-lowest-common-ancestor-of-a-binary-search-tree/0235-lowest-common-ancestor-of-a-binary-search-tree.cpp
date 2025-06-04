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
    void solve(TreeNode* root,TreeNode* node,vector<TreeNode*>& v){
        if(root==NULL) return;
        v.push_back(root);
        if(root==node) return;
        if(root->val>node->val) solve(root->left,node,v);
        else solve(root->right,node,v);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pv;
        solve(root,p,pv);
        vector<TreeNode*>pq;
        solve(root,q,pq);
        for(int i=pv.size()-1;i>=0;i--){
            for(int j=pq.size()-1;j>=0;j--){
                if(pv[i]==pq[j]) return pv[j];
            }
        }
        return nullptr;
        
    }
};