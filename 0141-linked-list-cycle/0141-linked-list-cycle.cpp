/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( head==NULL || head->next==NULL) return false;
        multiset<ListNode*>ms;
        ms.insert(head);
        ListNode* temp=head->next;
        while(temp!=NULL){
            if(ms.find(temp)!=ms.end()){
                return true;
            }
            ms.insert(temp);
            temp=temp->next;
        }
        return false;
        
    }
};