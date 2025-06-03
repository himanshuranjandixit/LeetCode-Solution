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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            if(q.front()==nullptr) return nullptr;
            int value= q.front()->val;
            TreeNode* node = q.front();
            q.pop();
            if(value==val) return node;
            if(value>val){
                q.push(node->left);
            }
            else q.push(node->right);
        }
        return nullptr;
        
    }
};