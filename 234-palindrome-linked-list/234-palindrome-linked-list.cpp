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
    ListNode* reverse(ListNode* head){
        if(head==NULL ||  head->next==NULL)return head;
        ListNode* prev=NULL;
        ListNode* pres=head;
        ListNode* nxt=head->next;
        while(pres){
            pres->next=prev;
            prev=pres;
            pres=nxt;
            if(nxt){
                nxt=nxt->next;
            }
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* f=head;
        ListNode* s=head;
        while(f && f->next){
            f=f->next->next;
            s=s->next;
        }
        ListNode* curr1=head;
        ListNode* curr2=reverse(s);
        while(curr1 && curr2){
            if(curr1->val!=curr2->val)return false;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return true;
    }
};