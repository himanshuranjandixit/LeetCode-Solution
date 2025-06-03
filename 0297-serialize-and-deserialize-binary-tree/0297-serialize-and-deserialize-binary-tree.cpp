/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial="";
        if(root==NULL) return serial;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node =q.front();
            q.pop();
            if(node){
                serial+=to_string(node->val) +'$';
                q.push(node->left);
                q.push(node->right);
            }
            else{
                serial+="N$";
            }
        }
        // for(auto it: serial){
        //     cout<<it;
        // }
        return serial;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data.substr(0, 2) == "N$") return nullptr;
        vector<string> tokens;
        string token = "";
        for(char c : data){
            if(c == '$'){
                tokens.push_back(token);
                token = "";
            }
            else{
                token += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i<tokens.size()){
            TreeNode* node = q.front();
            q.pop();
            if(tokens[i] != "N"){
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;
            if(i < tokens.size() && tokens[i] != "N"){
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));