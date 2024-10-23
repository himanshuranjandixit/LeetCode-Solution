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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return nullptr;
        int count=0;
        ListNode* temp1=head;
        while(temp1!=NULL){
            count++;
            temp1=temp1->next;
        }
        int mid=count/2;
        ListNode* temp=head;
        int cnt=1;
        while(cnt<mid){
            temp=temp->next;
            cnt++;
        }
        if(temp != NULL && temp->next != NULL) temp->next=temp->next->next;
        return head;


        
        
    }
};