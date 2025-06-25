/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(unordered_map<int,Node*>& mpp, Node* node, vector<int>& vis,Node* par){
        vis[node->val] = 1;
        for(auto it: node->neighbors){
            if(mpp.count(it->val)){
                par->neighbors.push_back(mpp[it->val]);
            }
            else{
                Node*  temp = new Node(it->val);
                par->neighbors.push_back(temp);
                mpp[temp->val]=temp;

            }
            if(!vis[it->val]){
                dfs(mpp,it,vis,mpp[it->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<int,Node*>mpp;
        Node* head = new Node(node->val);
        mpp[head->val] =head;
        vector<int>vis(101,0);
        dfs(mpp,node,vis,head);
        return head;
    }
};