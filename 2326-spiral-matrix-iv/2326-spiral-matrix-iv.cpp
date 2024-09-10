/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
//         vector<int>v;
//         ListNode* temp = head ;
//         while(temp!=NULL){
//             v.push_back(temp->val);
//             temp=temp->next;
//         }
//         int left=m*n-v.size();
//         while(left--){
//             v.push_back(-1);
//         }
//         int left=0;
//         int right=n-1;
//         int bottom =m-1;
//         int top=0;
//         vector<vector<int>ans(m,vector<int>(n));
//         while(left<right && bottom<top){
//             for(int i=0;i<)
//         }

        
//     }
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Store the east, south, west, north movements in a matrix.
        int i = 0, j = 0, cur_d = 0,
            movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(m, vector<int>(n, -1));

        for (; head != nullptr; head = head->next) {
            res[i][j] = head->val;
            int newi = i + movement[cur_d][0], newj = j + movement[cur_d][1];

            // If we bump into an edge or an already filled cell, change the
            // direction.
            if (min(newi, newj) < 0 || newi >= m || newj >= n ||
                res[newi][newj] != -1)
                cur_d = (cur_d + 1) % 4;
            i += movement[cur_d][0];
            j += movement[cur_d][1];
        }

        return res;
    }
};