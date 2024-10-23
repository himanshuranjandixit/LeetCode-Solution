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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mpp;
        for( ListNode* i =headA ; i!=NULL ;i=i->next){
            mpp[i]=i->val;
        }
        for(ListNode* i=headB;i!=NULL;i=i->next){
            if(mpp.find(i)!=mpp.end()) return i;
        }
        return NULL;
        
    }
};