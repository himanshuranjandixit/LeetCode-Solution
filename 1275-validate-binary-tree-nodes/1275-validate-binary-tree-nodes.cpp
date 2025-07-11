class Solution {
public:
    void isconnected(vector<vector<int>>& adj, vector<int>& visited, int node){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]) isconnected(adj,visited,it);
        }

    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>adj(n);
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if(rightChild[i] != -1){
                adj[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }
        for(int i = 0;i < n;i++){
            if(indegree[i] > 1) return false;
        }
        int root = -1;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 0){
                if(root != -1) return false; 
                root = i;
            }
        }
        if(root==-1) return false;
        vector<int>visited(n,0);
        isconnected(adj,visited,root);
        for(auto it : visited) if(it==0) return false;
        return true;
    }
};