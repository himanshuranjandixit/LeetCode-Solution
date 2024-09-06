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
    ListNode* middleNode(ListNode* head) {
        // ListNode* temp=head;
        // int cnt=0;
        // while(temp!=nullptr){
        //     cnt++;
        //     temp=temp->next;
        // }
        // ListNode* mid;
        // ListNode* temp1=head;
        // for(int i=1;i<=cnt/2;i++){
        //     temp1=temp1->next;
           

        // }
        // return temp1;
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow; 
        
    }
};