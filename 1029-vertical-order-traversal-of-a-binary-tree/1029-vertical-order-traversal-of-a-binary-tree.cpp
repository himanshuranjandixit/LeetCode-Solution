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
    int minrow=INT_MAX;
    int mincol=INT_MAX;
    int maxrow=INT_MIN;
    int maxcol=INT_MIN;
public:
    void solve(TreeNode* root, vector<pair<int,pair<int,int>>>& coor,int row,int col){
        if(root==NULL) return;
        coor.push_back(make_pair(root->val,make_pair(row,col)));
        minrow=min(minrow,row);
        maxrow=max(maxrow,row);
        mincol=min(mincol,col);
        maxcol=max(maxcol,col);
        solve(root->left,coor,row+1,col-1);
        solve(root->right,coor,row+1,col+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>>coor;
        solve(root,coor,0,0);
        sort(coor.begin(),coor.end(),[](const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b){
            if (a.second.second!=b.second.second) return a.second.second<b.second.second;
            if(a.second.first!=b.second.first) return a.second.first<b.second.first;
            return a.first<b.first;

        });
        vector<vector<int>>ans(maxcol-mincol+1);
        for(int i=0;i<coor.size();i++){
            ans[coor[i].second.second-mincol].push_back(coor[i].first);

        }
        return ans;
    }
};