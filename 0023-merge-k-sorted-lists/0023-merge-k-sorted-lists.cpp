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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>>pq;
        vector<ListNode*>v;
        for(auto it:lists){
            if(it != nullptr) pq.push({it->val,it});
        }
        if(pq.size()==0) return nullptr;
        ListNode* ans= new ListNode();
        ListNode* head = ans;
        while(!pq.empty()){
            ListNode* temp = pq.top().second;
            pq.pop();
            if(temp->next != nullptr) pq.push({temp->next->val,temp->next});
            if(ans== nullptr){
                ans= temp;
                continue;
            }
            ans->next = temp;
            ans = ans->next;
        }
        return head->next;

        
    }
};