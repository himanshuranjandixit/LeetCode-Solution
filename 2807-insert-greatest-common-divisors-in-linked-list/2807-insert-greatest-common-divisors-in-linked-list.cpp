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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* temp1=head;
        ListNode* temp2= head->next;
        while (temp2!=NULL){
            int gcd =GCD(temp1->val, temp2->val);
            ListNode* temp3 = new ListNode(gcd);
            temp1->next = temp3;
            temp3->next =temp2;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return head;
    }

private:
    int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};