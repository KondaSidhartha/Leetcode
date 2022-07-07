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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* pres=head;
        ListNode* next=head->next;
        while(pres!=NULL){
            pres->next=prev;
            prev=pres;
            pres=next;
            if(next!=NULL){
                next=next->next;
            }
        }
        head=prev;
        return head;
    }
};