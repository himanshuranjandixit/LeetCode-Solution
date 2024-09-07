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
        // multiset<ListNode*>ms;
        // ListNode* temp=head;
        // ms.insert(temp);
        // int cnt=0;
        // while(temp!=NULL){
        //     temp=temp->next;
        //     cnt++;
        //     if(ms.find(temp)!=ms.end()){
        //         return temp;
        //     }
        //     ms.insert(temp);
        // }
        // return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* temp=head;
                while(temp!=slow){
                    temp=temp->next;
                    slow=slow->next;
                    
                }
                return slow;
            }
        }
        return NULL;

        
    }
};