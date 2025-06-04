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
class BSTIterator {
    vector<int>inorder;
    int i=0;
public:
    void solve(TreeNode* root){
        if(root==NULL) return;
        inorder.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    BSTIterator(TreeNode* root) {
        solve(root);
        sort(inorder.begin(),inorder.end());
    }
    
    int next() {
        i++;
        return inorder[i-1];
        
    }
    
    bool hasNext() {
        if(i>=inorder.size()) return false;
        return true;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */