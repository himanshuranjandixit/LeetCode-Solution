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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        multiset<ListNode*>ms;
        ListNode* temp=head;
        ms.insert(temp);
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
            if(ms.find(temp)!=ms.end()){
                return temp;
            }
            ms.insert(temp);
        }
        return NULL;
        
    }
};