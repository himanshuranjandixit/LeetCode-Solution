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
    void solve(TreeNode* root, vector<TreeNode*>& inorder){
        if(root==NULL) return;
        solve(root->left,inorder);
        inorder.push_back(root);
        solve(root->right,inorder);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>inorder1;
        solve(root,inorder1);
        vector<TreeNode*>inorder2=inorder1;
        sort(inorder2.begin(),inorder2.end(),[](const TreeNode* node1, const TreeNode* node2 ){
            return node1->val<node2->val;
        });
        int i=0;
        int j=0;
        while(i<inorder1.size() && j<inorder1.size()){
            if(inorder1[i]!=inorder2[j]) {
                break;
            }
            i++;j++;
        }
        swap(inorder1[i]->val,inorder2[j]->val);
    }
};