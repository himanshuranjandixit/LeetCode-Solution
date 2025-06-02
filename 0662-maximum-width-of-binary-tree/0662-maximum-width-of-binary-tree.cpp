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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int minindx= q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                int indx=q.front().second-minindx;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=indx;
                if(i==size-1) last=indx;
                if(node->left!=NULL) q.push({node->left,indx*2+1});
                if(node->right!=NULL) q.push({node->right,indx*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
        
    }
};