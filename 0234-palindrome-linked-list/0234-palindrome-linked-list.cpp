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
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int size =v.size();
        int n=size;
        ListNode*pal=head;
        while(pal!=NULL){
            if(pal->val!=v[size-1]){
                return false;
            }
            pal=pal->next;
            size--;
        }
        return true;

        
        
    }
};