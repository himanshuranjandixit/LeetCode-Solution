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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return nullptr;

        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        if(size==n) return head->next;
        int nodenum = size-n-1;
        ListNode* temp1=head;
        int cnt=0;
        while(cnt<nodenum){
            temp1=temp1->next;
            cnt++;
        }
        if(n==1){
            temp1->next=nullptr;
            return head;
        }
        temp1->next=temp1->next->next;
        return head;



    }
};