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
    ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    //    ListNode* even =head;
    //    ListNode* odd=head->next;
    //    ListNode* jadoo=odd;
    //    while(odd!=NULL && odd->next!=NULL){
    //     even->next=odd->next;
    //     even=even->next;
    //     odd->next=even->next;
    //     odd=odd->next;
    //    }
    //    even->next=jadoo;
    //    return head;
    vector<int>even;
    ListNode* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        even.push_back(temp->val);
        temp=temp->next->next;
    }
    if(temp) even.push_back(temp->val);
    ListNode* temp1=head->next;
    while(temp1!=NULL && temp1->next!=NULL){
        even.push_back(temp1->val);
        temp1=temp1->next->next;
    }
    if(temp1) even.push_back(temp1->val);
    ListNode* ans=head;
    int i=0;
    while(i<even.size()){
        ans->val=even[i];
        ans=ans->next;
        i++;
    }
    return head;
    

    
    }
    
};